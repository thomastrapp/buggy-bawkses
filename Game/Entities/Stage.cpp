#include "Game/Entities/Stage.h"

namespace Game
{
  namespace Entities
  {
    
Stage::Stage(boost::shared_ptr<Game::Config> conf, Game::World& game_world)
: Entity(conf, game_world),
  config(conf),
  world(game_world),
  left(
    conf,
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        20.0f,
        static_cast<float>(this->config->get<int>("window-height"))
      ), 
      sf::Vector2f( // position
        0.0f,
        static_cast<float>(this->config->get<int>("window-height")) / 2.0f
      )
    )
  ),
  bottom(
    conf,
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        static_cast<float>(this->config->get<int>("window-width")), 
        20.0f
      ), 
      sf::Vector2f( // position
        static_cast<float>(this->config->get<int>("window-width")) / 2.0f,
        static_cast<float>(this->config->get<int>("window-height"))
      )
    )
  ),
  right(
    conf, 
    game_world,
    Game::Entities::RectangleDef(
      sf::Vector2f( // size
        20.0f,
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

