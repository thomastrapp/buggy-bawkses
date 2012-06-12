#ifndef GAMEENTITIESPLAYER_H
#define GAMEENTITIESPLAYER_H

#include <boost/shared_ptr.hpp>

#include "Game/Config.h"
#include "Game/World.h"
#include "Game/Util/Util.h"
#include "Game/Entity.h"
#include "Game/Entities/Type.h"

namespace Game
{
  namespace Entities
  {
  
class Player : public Game::Entity
{
  class FootContactListener : public b2ContactListener
  {
    public:
      FootContactListener();
      ~FootContactListener() {}
      
      void BeginContact(b2Contact* contact);
      void EndContact(b2Contact* contact);
      
      bool is_foot_on_ground();
            
    private:
      FootContactListener(const FootContactListener&);
      FootContactListener& operator=(const FootContactListener&);
      
      bool _fixture_is_player_foot(b2Fixture* fixture);
      
      unsigned int foot_contacts;
  };

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
  
  FootContactListener foot_sensor;
};

  }
}

#endif // GAMEENTITIESPLAYER_H
