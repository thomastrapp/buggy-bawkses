#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <boost/foreach.hpp>
#include <boost/shared_ptr.hpp>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game/Window.h"
#include "Game/Config.h"

namespace Game
{
  // Forward declaration to solve circular dependency between World and Entity
  class Entity;
  // and World and Player
  class Player;
  
  typedef std::vector< boost::shared_ptr<Game::Entity> > t_entities;

  class World
  {
  public:
    World(boost::shared_ptr<Game::Config> conf);
    ~World() {}
    
    void step_default();
    void render(Game::Window& window);
    void handle_input(const sf::Event& event);
    boost::shared_ptr<b2World> b2world() const;
    sf::Vector2f get_stage_size() const;
    
  private:
    World(Game::World const&);
    World& operator=(Game::World const&);
    
    void _setup_stage();
    void _update_entities();
    void _render_entities(sf::RenderTarget& renderer);
    
    boost::shared_ptr<b2World>      b2_world;
    boost::shared_ptr<Game::Config> config;

    t_entities entities;
  };
}

#endif // GAMEWORLD_H
