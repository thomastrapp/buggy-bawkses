#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <cstdlib>
#include <boost/shared_ptr.hpp>
#include <Box2D/Box2D.h>

#include "Game/Config.h"
#include "Game/Exception.h"
#include "Game/Window.h"
#include "Game/World.h"

#include "3rdParty/DebugDraw.h"

namespace Game 
{
  class Controller
  {
  public:
    Controller(boost::shared_ptr<Game::Config> conf);
    ~Controller();
    
    void start();
    void step();
    void render();
    void handle_event(const sf::Event& sfml_event);
    void handle_input(const sf::Event& input);
  
  private:
    Controller(Game::Controller const&);
    Controller& operator=(Game::Controller const&);
  
    boost::shared_ptr<Game::Config> config;
    
    Game::Window window;
    Game::World world;
    DebugDraw debugDraw;
  };
}

#endif // GAMECONTROLLER_H
