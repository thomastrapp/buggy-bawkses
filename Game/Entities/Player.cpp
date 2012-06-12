#include "Player.h"

namespace Game
{
  namespace Entities
  {
  
Player::Player(boost::shared_ptr<Game::Config> conf, Game::World& game_world)
: Entity(conf, game_world),
  physics(NULL),
  visible(),
  foot_sensor()
{
  {
    const sf::Vector2f stage_size(
      static_cast<float>(conf->get<int>("window-width")),
      static_cast<float>(conf->get<int>("window-height"))
    );
    sf::Vector2f box_center_coord(stage_size.x / 2.0f, stage_size.y / 2.0f);
    b2BodyDef playerDef;
    playerDef.type = b2_dynamicBody;
    // disable rotation
    playerDef.fixedRotation = true;
    playerDef.position.Set(
      Game::Util::pixel_to_meter(box_center_coord.x),
      Game::Util::pixel_to_meter(box_center_coord.y)
    );
    
    this->physics = game_world.b2world()->CreateBody(&playerDef);
  }
  
  sf::Vector2f box_center_size(10.0f, 30.0f);
  
  {
    b2PolygonShape playerBox;
    playerBox.SetAsBox(
      Game::Util::pixel_to_meter(box_center_size.x),
      Game::Util::pixel_to_meter(box_center_size.y)
    );
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &playerBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;
    b2Fixture * playerFixture = this->physics->CreateFixture(&fixtureDef);
    playerFixture->SetUserData(
      Game::Entities::Type::to_user_data(Game::Entities::Type::PLAYER)
    );
  }
  
  // Player foot
  {
    b2PolygonShape footShape;
    footShape.SetAsBox(
      Game::Util::pixel_to_meter(box_center_size.x) / 2.0f,
      Game::Util::pixel_to_meter(box_center_size.x) / 2.0f,
      b2Vec2(
        0.0f,
        Game::Util::pixel_to_meter(box_center_size.y)
      ),
      0.0f
    );
    
    b2FixtureDef footFixtureDef;
    footFixtureDef.shape = &footShape;
    footFixtureDef.isSensor = true;
    
    b2Fixture * footSensorFixture = 
      this->physics->CreateFixture(&footFixtureDef);
    
    footSensorFixture->SetUserData(
      Game::Entities::Type::to_user_data(Game::Entities::Type::PLAYER_FOOT)
    );
    
    game_world.b2world()->SetContactListener(&(this->foot_sensor));
  }
  
  {
    this->visible.setFillColor(sf::Color(255, 68, 0));
    this->visible.setSize(box_center_size * 2.0f);
    this->visible.setOrigin(box_center_size);
  }
}

void Player::handle_input(const sf::Event& event)
{
  if( event.type != sf::Event::KeyPressed )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }
  
  switch( event.key.code )
  {
    case sf::Keyboard::Up:
    {
      if( this->foot_sensor.is_foot_on_ground() )
      {
        this->physics->ApplyLinearImpulse(
          b2Vec2(0.0f, -0.3f), this->physics->GetPosition()
        );
      }
      break;
    }
    case sf::Keyboard::Right:
    {
      this->physics->ApplyLinearImpulse(
        b2Vec2(0.3f, 0.0f), this->physics->GetPosition()
      );
      break;
    }
    case sf::Keyboard::Left:
    {
      this->physics->ApplyLinearImpulse(
        b2Vec2(-0.3f, 0.0f), this->physics->GetPosition()
      );
      break;
    }
    default:
    {
      break;
    }
  }
}

void Player::render(sf::RenderTarget& renderer)
{
  renderer.draw(this->visible);
}

void Player::update()
{
  this->sync_visible(this->physics, this->visible);
}

Player::FootContactListener::FootContactListener()
: foot_contacts(0)
{
}

void Player::FootContactListener::BeginContact(b2Contact* contact)
{
  if( contact == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }
  
  if( this->_fixture_is_player_foot(contact->GetFixtureA()) ||
      this->_fixture_is_player_foot(contact->GetFixtureB())    )
  {
    ++this->foot_contacts;
  }
}

void Player::FootContactListener::EndContact(b2Contact* contact)
{
  if( contact == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }

  if( this->_fixture_is_player_foot(contact->GetFixtureA()) ||
      this->_fixture_is_player_foot(contact->GetFixtureB())    )
  {
    --this->foot_contacts;
  }
}

bool Player::FootContactListener::_fixture_is_player_foot(b2Fixture* fixture)
{
  if( fixture == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }
  
  using namespace Game::Entities;
  
  void * user_data = fixture->GetUserData();
  if( user_data == NULL )
  {
    return false;
  }
  else
  {
    const Type::t_entities_type entity_type = Type::to_entity_type(user_data);

    return ( entity_type == Type::PLAYER_FOOT );
  }
}

bool Player::FootContactListener::is_foot_on_ground()
{
  return ( this->foot_contacts > 0 );
}

  }
}


