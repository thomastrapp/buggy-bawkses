#include "Game/Entities/Wall.h"
#include "Game/World.h"

namespace Game
{
namespace Entities
{

Wall::Wall(
  Game::World& game_world,
  const Game::Entities::RectangleDef& rect_def
)
: Entity(Game::Entities::Id::WALL),
  physics(NULL),
  visible(rect_def.size)
{
  // setup the Wall
  {
    b2BodyDef blockDef;
    blockDef.position.Set(
      Game::Util::pixel_to_meter(rect_def.pos.x),
      Game::Util::pixel_to_meter(rect_def.pos.y)
    );
    
    this->physics = game_world.b2world()->CreateBody(&blockDef);
  }
  
  // setup the Wall's appearance in the physics simulation
  {
    b2PolygonShape blockBox;
    blockBox.SetAsBox(
      Game::Util::pixel_to_meter(rect_def.size.x / 2.0f),
      Game::Util::pixel_to_meter(rect_def.size.y / 2.0f)
    );
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &blockBox;
    fixtureDef.restitution = 0.0f;
    fixtureDef.friction = 0.0f;
    
    this->physics->CreateFixture(&fixtureDef);
  }
 
  // visible (sfml RectangleShape that gets rendered on screen)
  {
    this->visible.setFillColor(sf::Color(0, 255, 0));
    this->visible.setOrigin(rect_def.size / 2.0f);
    this->visible.setPosition(rect_def.pos);
  }
}

void Wall::render(sf::RenderTarget& renderer)
{
  renderer.draw(this->visible);
}

}
}
