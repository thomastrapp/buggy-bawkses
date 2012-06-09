#ifndef GAMEENTITIESRECTANGLE_H
#define GAMEENTITIESRECTANGLE_H

#include <boost/shared_ptr.hpp>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Config.h"
#include "Game/Entity.h"
#include "Game/World.h"
#include "Game/Entities/RectangleDef.h"

namespace Game
{
  namespace Entities
  {

class Rectangle : public Game::Entity
{
public:
  Rectangle(
    boost::shared_ptr<Game::Config> conf, 
    Game::World& game_world,
    const Game::Entities::RectangleDef& rect_def
  );
  ~Rectangle() {}
  
  void render(sf::RenderTarget& renderer);
  void update();

private:
  Rectangle(const Rectangle&);
  Rectangle& operator=(const Rectangle&);
  
  boost::shared_ptr<Game::Config> config;
  Game::World& world;

  b2Body * physics;
  sf::RectangleShape visible;
};

  }
}

#endif // GAMEENTITIESRECTANGLE_H
