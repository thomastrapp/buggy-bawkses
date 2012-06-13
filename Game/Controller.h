#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <cstdlib>
#include <boost/shared_ptr.hpp>
#include <Box2D/Box2D.h>

#include "Game/Config.h"
#include "Game/Exception.h"
#include "Game/Window.h"
#include "Game/World.h"

#ifdef ENABLE_DEBUG_DRAW
  #include "Game/Util/DebugDraw.h"
#endif

namespace Game 
{

/**
 * @brief Controls everything.
 *
 * The Controller has a window (the canvas) and a world (a collection of
 * entities).
 *
 * Controller::start is a "game loop".
 */
class Controller
{
public:
  /**
   * @brief Construct a Controller
   *
   * @param conf A shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as internal key/value pairs.
   */
  Controller(boost::shared_ptr<Game::Config> conf);
  ~Controller() {}
  
  /**
   * @brief Start the game loop
   * 
   * Takes care of events (e.g. user input or a close request).
   * Steps and renders the world. 
   */
  void start();
  
  /**
   * @brief Step the world
   */
  void step();
  
  /**
   * @brief Render the world
   */
  void render();
  
  /**
   * @brief Take care of events
   *
   * If the event.type is a sf::Event::KeyPressed the event gets passed on to
   * Controller::handle_input.
   *
   * @param sfml_event
   */
  void handle_event(const sf::Event& sfml_event);
  
  /**
   * @brief Take care of user input
   *
   * The input event gets passed on to the world.
   *
   * @param input
   */
  void handle_input(const sf::Event& input);

private:
  Controller(Game::Controller const&);
  Controller& operator=(Game::Controller const&);

  /**
   * @brief A shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as internal key/value pairs.
   */
  boost::shared_ptr<Game::Config> config;
  
  /**
   * @brief The Window that will render the world
   */
  Game::Window window;
  
  /**
   * @brief The world that governs entities
   */
  Game::World world;
  
  #ifdef ENABLE_DEBUG_DRAW
    /**
     * @brief debug_draw Draws the physical representation of Box2d objects.
     */
    Game::Util::DebugDraw debug_draw;
  #endif
};

}

#endif // GAMECONTROLLER_H
