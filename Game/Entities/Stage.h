#ifndef GAMEENTITIESSTAGE_H
#define GAMEENTITIESSTAGE_H

#include <iostream>
#include <boost/shared_ptr.hpp>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Entity.h"
#include "Game/Config.h"
#include "Game/Window.h"
#include "Game/Util/Util.h"

namespace Game 
{
  // forward declaration to solve circular dependency between World and Entity
  class world;
  
  namespace Entities
  {

class Stage : public Game::Entity
{
public:
  Stage(boost::shared_ptr<Game::Config> conf, Game::World& game_world);
  ~Stage() {}
  
  void render(sf::RenderTarget& renderer);
  void update();

private:
  Stage(const Stage&);
  Stage& operator=(const Stage&);

  boost::shared_ptr<Game::Config> config;

  b2Body * physics;
  sf::RectangleShape visible;
};

  }
}

#endif // GAMEENTITIESSTAGE_H
