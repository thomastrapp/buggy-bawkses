#include "Player.h"

namespace Game
{
  namespace Entities
  {
  
Player::Player(boost::shared_ptr<Game::Config> conf, Game::World& game_world)
: Entity(Game::Entities::Id::PLAYER),
  physics(NULL),
  visible(),
  foot()
{
  // setup the player
  {
    const sf::Vector2f stage_size(
      static_cast<float>(conf->get<int>("window-width")),
      static_cast<float>(conf->get<int>("window-height"))
    );
    sf::Vector2f box_center_coord(stage_size.x / 2.0f, stage_size.y / 2.0f);
    b2BodyDef playerDef;
    playerDef.type = b2_dynamicBody;
    // disable rotation, player shall always be upright
    playerDef.fixedRotation = true;
    playerDef.position.Set(
      Game::Util::pixel_to_meter(box_center_coord.x),
      Game::Util::pixel_to_meter(box_center_coord.y)
    );
    
    this->physics = game_world.b2world()->CreateBody(&playerDef);
  }
  
  sf::Vector2f player_size(
    conf->get<float>("player-size-x"),
    conf->get<float>("player-size-y")
  );
  
  /**
   * To easily detect Player collision with "grounds" we set up a foot, that
   * does not participate in the physics simulation, but is subject to 
   * collisions.
   * 
   * We pass a pointer to this to the user data of the fixture, to instruct 
   * the CollisionDispatcher to notify us if we collide with anything.
   *
   * We therefore can later determine whether the Player is in air or on solid
   * ground ("Can the player jump?").
   */
  this->foot.bind_to_body(this->physics, player_size);
  
  // setup the player's appearance in the physics simulation
  {
    b2PolygonShape playerBox;
    playerBox.SetAsBox(
      Game::Util::pixel_to_meter(player_size.x),
      Game::Util::pixel_to_meter(player_size.y)
    );
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &playerBox;
    fixtureDef.density = conf->get<float>("player-density");
    fixtureDef.friction = conf->get<float>("player-friction");
    this->physics->CreateFixture(&fixtureDef);
  }
  
  // visible (sfml shape that gets rendered on screen)
  {
    this->visible.setFillColor(sf::Color(255, 68, 0));
    // sfml wants the size in total width/height
    this->visible.setSize(player_size * 2.0f);
    // set sfml origin to the center of the shape (just like in box2d)
    this->visible.setOrigin(player_size);
  }
}

void Player::handle_input(const sf::Event& event)
{
  // Be defensive
  if( event.type != sf::Event::KeyPressed )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }
  
  switch( event.key.code )
  {
    case sf::Keyboard::Up:
    {
      if( this->foot.is_on_ground() )
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

  }
}


