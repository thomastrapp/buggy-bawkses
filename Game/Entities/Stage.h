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
#include "Game/Entities/Rectangle.h"
#include "Game/Entities/RectangleDef.h"

namespace Game 
{
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
  Game::World& world;
  
  Game::Entities::Rectangle left;
  Game::Entities::Rectangle bottom;
  Game::Entities::Rectangle right;
};

  }
}

#endif // GAMEENTITIESSTAGE_H
