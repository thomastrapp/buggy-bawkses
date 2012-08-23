#include "Game/Entities/Wall.h"
#include "Game/World.h"

namespace Game
{
namespace Entities
{

Wall::Wall(
  Game::Entities::Id::t_entities_id wall_entity_id,
  Game::World& game_world,
  const Game::Entities::RectangleDef& rect_def
)
: Entity(wall_entity_id),
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

Wall::~Wall()
{
  this->physics->GetWorld()->DestroyBody(this->physics);
}

void Wall::render(sf::RenderTarget& renderer)
{
  renderer.draw(this->visible);
}

State::t_entities_state Wall::update(const sf::View& view)
{
  const b2Vec2 new_position(
    this->physics->GetPosition().x, 
    Game::Util::pixel_to_meter(
      view.getCenter().y
    )
  );
  
  this->physics->SetTransform(new_position, this->physics->GetAngle());
  this->sync_visible(this->physics, this->visible);
  
  return State::NONE;
}

}
}
