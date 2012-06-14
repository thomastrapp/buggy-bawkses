#include "Game/Entities/Stage.h"

namespace Game
{
  namespace Entities
  {
    
Stage::Stage(boost::shared_ptr<Game::Config> conf, Game::World& game_world)
: Entity(Game::Entities::Id::STAGE),
  left( // Rectangle
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        conf->get<float>("stage-walls-width"),
        static_cast<float>(conf->get<int>("window-height"))
      ), 
      sf::Vector2f( // position
        0.0f,
        static_cast<float>(conf->get<int>("window-height")) / 2.0f
      ),
      0.0f, // friction
      Game::Entities::Id::WALL_LEFT
    )
  ),
  bottom( // Rectangle
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        static_cast<float>(conf->get<int>("window-width")), 
        conf->get<float>("stage-walls-width")
      ), 
      sf::Vector2f( // position
        static_cast<float>(conf->get<int>("window-width")) / 2.0f,
        static_cast<float>(conf->get<int>("window-height"))
      ),
      1.0f, // friction
      Game::Entities::Id::WALL_BOTTOM
    )
  ),
  right( // Rectangle
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        conf->get<float>("stage-walls-width"),
        static_cast<float>(conf->get<int>("window-height"))
      ), 
      sf::Vector2f( // position
        static_cast<float>(conf->get<int>("window-width")),
        static_cast<float>(conf->get<int>("window-height")) / 2.0f
      ),
      0.0f, // friction
      Game::Entities::Id::WALL_RIGHT
    )
  )
{
}

void Stage::render(sf::RenderTarget& renderer)
{
  this->left.render(renderer);
  this->bottom.render(renderer);
  this->right.render(renderer);
}

void Stage::update()
{
}

  }
}

