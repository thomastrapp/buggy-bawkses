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
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        conf->get<float>("stage-walls-width"),
        // FIXME: Walls shall be of reasonable height. 
        // Walls get stacked on top of each other.
        // A Wall will be dynamically created, if the user steers towards space
        // without a wall
        // if the old wall gets out of sight, it shall be deleted
        static_cast<float>(conf->get<int>("window-height")) * 10.0f
      ), 
      sf::Vector2f( // position
        0.0f,
        -1.0f * static_cast<float>(conf->get<int>("window-height")) * 10.0f / 2.0f
      )
    )
  )
{
}

}
}

