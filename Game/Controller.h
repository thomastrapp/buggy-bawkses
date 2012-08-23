/*
  This file is part of the "Buggy Bawkses" Project.

  Copyright (C) 2012 Thomas Trapp; mailto: bawkses@thomastrapp.com

  "Buggy Bawkses" is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, 
  Boston, MA  02110-1301, USA.

  See COPYING for details.
*/

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

/**
 * @brief Global namespace
 */
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
   * @param conf A shared_ptr to Game::Config, a class that stores user
   * supplied configuration, as well as internal key/value pairs.
   */
  explicit Controller(boost::shared_ptr<Game::Config> conf);
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
   * @param sfml_event An event from SFML
   */
  void handle_event(const sf::Event& event);

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
