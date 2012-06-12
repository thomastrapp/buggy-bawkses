#include "Game/Entities/Stage.h"

namespace Game
{
  namespace Entities
  {
    
Stage::Stage(boost::shared_ptr<Game::Config> conf, Game::World& game_world)
: Entity(conf, game_world),
  config(conf),
  world(game_world),
  left( // Rectangle
    conf,
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        this->config->get<float>("stage-walls-width"),
        static_cast<float>(this->config->get<int>("window-height"))
      ), 
      sf::Vector2f( // position
        0.0f,
        static_cast<float>(this->config->get<int>("window-height")) / 2.0f
      )
    )
  ),
  bottom( // Rectangle
    conf,
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        static_cast<float>(this->config->get<int>("window-width")), 
        this->config->get<float>("stage-walls-width")
      ), 
      sf::Vector2f( // position
        static_cast<float>(this->config->get<int>("window-width")) / 2.0f,
        static_cast<float>(this->config->get<int>("window-height"))
      )
    )
  ),
  right( // Rectangle
    conf, 
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        this->config->get<float>("stage-walls-width"),
        static_cast<float>(this->config->get<int>("window-height"))
      ), 
      sf::Vector2f( // position
        static_cast<float>(this->config->get<int>("window-width")),
        static_cast<float>(this->config->get<int>("window-height")) / 2.0f
      )
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

