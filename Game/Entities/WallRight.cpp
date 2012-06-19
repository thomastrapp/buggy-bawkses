#include "Game/Entities/WallRight.h"

namespace Game
{
namespace Entities
{

WallRight::WallRight(
  boost::shared_ptr<Game::Config> conf, 
  Game::World& game_world
)
: Wall(
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        conf->get<float>("stage-walls-width"),
        static_cast<float>(conf->get<int>("window-height")) * 10.0f
      ), 
      sf::Vector2f( // position
        static_cast<float>(conf->get<int>("window-width")),
        -1.0f * static_cast<float>(conf->get<int>("window-height")) * 10.0f / 2.0f
      )
    )
  )
{
}

}
}
