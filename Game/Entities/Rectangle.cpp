#include "Game/Entities/Rectangle.h"

namespace Game
{
  namespace Entities
  {

Rectangle::Rectangle(
  boost::shared_ptr<Game::Config> conf, 
  Game::World& game_world,
  const Game::Entities::RectangleDef& rect_def
)
: Entity(conf, game_world),
  config(conf),
  world(game_world),
  physics(NULL),
  visible(rect_def.size)
{
  {
    b2BodyDef blockDef;
    blockDef.position.Set(
      Game::Util::pixel_to_meter(rect_def.pos.x),
      Game::Util::pixel_to_meter(rect_def.pos.y)
    );
    
    this->physics = this->world.b2world()->CreateBody(&blockDef);
  }
  
  {
    b2PolygonShape blockBox;
    blockBox.SetAsBox(
      Game::Util::pixel_to_meter(rect_def.size.x / 2.0f),
      Game::Util::pixel_to_meter(rect_def.size.y / 2.0f)
    );
    this->physics->CreateFixture(&blockBox, 0.0f);
  }
 
  {
    this->visible.setFillColor(sf::Color(0, 255, 0));
    this->visible.setOrigin(rect_def.size / 2.0f);
    this->visible.setPosition(rect_def.pos);
  }
}

void Rectangle::render(sf::RenderTarget& renderer)
{
  renderer.draw(this->visible);
}

void Rectangle::update()
{
}

  }
}
