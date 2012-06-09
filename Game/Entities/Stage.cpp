#include "Game/Entities/Stage.h"

namespace Game
{
  namespace Entities
  {
    
Stage::Stage(boost::shared_ptr<Game::Config> conf, Game::World& game_world)
: Entity(conf, game_world),
  config(conf),
  physics(NULL),
  visible()
{
  sf::Vector2f stage_size = game_world.get_stage_size();
  sf::Vector2f box_center_coord(stage_size.x / 2.0f, stage_size.y);
  sf::Vector2f box_center_size(stage_size.x / 2.0f, 5.0f);
  
  {
    b2BodyDef groundDef;
    groundDef.position.Set(
      Game::Util::pixel_to_meter(box_center_coord.x),
      Game::Util::pixel_to_meter(box_center_coord.y)
    );
    
    this->physics = game_world.b2world()->CreateBody(&groundDef);
  }
  
  {
    b2PolygonShape groundBox;
    groundBox.SetAsBox(
      Game::Util::pixel_to_meter(box_center_size.x),
      Game::Util::pixel_to_meter(box_center_size.y)
    );
    this->physics->CreateFixture(&groundBox, 0.0f);
  }
 
  {
    sf::Vector2f box_size(box_center_size.x * 2.0f, box_center_size.y * 2.0f);
    this->visible.setFillColor(sf::Color(255, 0, 0));
    this->visible.setSize(box_size);
    this->visible.setOrigin(box_center_size);
    this->sync_visible(this->physics, this->visible);
  }
}

void Stage::render(sf::RenderTarget& renderer)
{
  renderer.draw(this->visible);
}

void Stage::update()
{
}


  }
}

