#include "Game/Entities/WallLeft.h"

namespace Game
{
namespace Entities
{

WallLeft::WallLeft(
  boost::shared_ptr<Game::Config> conf, 
  Game::World &game_world
)
: Wall(
    Game::Entities::Id::WALL_LEFT, 
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        conf->get<float>("stage-walls-width"),
        static_cast<float>(conf->get<int>("window-height")) 
          * conf->get<float>("wall-height-scale")
      ), 
      sf::Vector2f( // position
        0.0f,
        -1.0f * static_cast<float>(conf->get<int>("window-height")) 
          * conf->get<float>("wall-height-scale") / 2.0f
      )
    )
  )
{
}

}
}

