#ifndef PLAYER_H
#define PLAYER_H

#include <boost/shared_ptr.hpp>

#include "Game/Config.h"
#include "Game/World.h"
#include "Game/Util/Util.h"
#include "Game/Entity.h"

namespace Game
{
  namespace Entities
  {
  
class Player : public Game::Entity
{
public:
  Player(boost::shared_ptr<Game::Config> conf, Game::World& game_world);
  ~Player() {}
  
  void render(sf::RenderTarget& renderer);
  void update();
  
  void handle_input(const sf::Event& event);

private:
  Player(const Player&);
  Player& operator=(const Player&);

  b2Body * physics;
  sf::RectangleShape visible;
};

  }
}

#endif // PLAYER_H
