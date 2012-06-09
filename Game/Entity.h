#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <boost/shared_ptr.hpp>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Config.h"
#include "Game/World.h"
#include "Game/Util/Util.h"
 
namespace Game
{

class Entity
{
public:
  Entity(boost::shared_ptr<Game::Config> conf, Game::World& game_world);
  virtual ~Entity() {}
  
  virtual void render(sf::RenderTarget& renderer) = 0;
  virtual void update() = 0;
  virtual void handle_input(const sf::Event&)
  {
  }
  
  void sync_visible(const b2Body * source, sf::Transformable& target);
  
private:
  Entity(const Entity&);
  Entity& operator=(const Entity&);
  
  boost::shared_ptr<Game::Config> config;
  Game::World& world;
};

}

#endif // GAMEENTITY_H
