#include "Player.h"

namespace Game
{
  namespace Entities
  {
  
Player::Player(boost::shared_ptr<Game::Config> conf, Game::World& game_world)
: Entity(conf, game_world),
  physics(NULL),
  visible()
{
  {
    const sf::Vector2f stage_size(
      static_cast<float>(conf->get<int>("window-width")),
      static_cast<float>(conf->get<int>("window-height"))
    );
    sf::Vector2f box_center_coord(stage_size.x / 2.0f, stage_size.y / 2.0f);
  
    b2BodyDef playerDef;
    playerDef.type = b2_dynamicBody;
    playerDef.fixedRotation = true;
    playerDef.position.Set(
      Game::Util::pixel_to_meter(box_center_coord.x),
      Game::Util::pixel_to_meter(box_center_coord.y)
    );
    
    this->physics = game_world.b2world()->CreateBody(&playerDef);
  }
  
  sf::Vector2f box_center_size(10.0f, 50.0f);
  
  {
    b2PolygonShape playerBox;
    playerBox.SetAsBox(
      Game::Util::pixel_to_meter(box_center_size.x),
      Game::Util::pixel_to_meter(box_center_size.y)
    );
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &playerBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.5f;
    
    this->physics->CreateFixture(&fixtureDef);
  }
  
  {
    sf::Vector2f box_size(box_center_size.x * 2.0f, box_center_size.y * 2.0f);
    this->visible.setFillColor(sf::Color(255, 68, 0));
    this->visible.setSize(box_size);
    this->visible.setOrigin(box_center_size);
    this->sync_visible(this->physics, this->visible);
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
      this->physics->ApplyForce(b2Vec2(0.0f, 50.0f), this->physics->GetPosition());
      break;
    }
    case sf::Keyboard::Right:
    {
      this->physics->ApplyForce(b2Vec2(10.0f, 0.0f), this->physics->GetPosition());
      break;
    }
    case sf::Keyboard::Left:
    {
      this->physics->ApplyForce(b2Vec2(-10.0f, 0.0f), this->physics->GetPosition());
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

  }
}


