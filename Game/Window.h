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

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game/Config.h"

namespace Game
{
/**
 * @brief A wrapper for sf::RenderWindow
 *
 * In the initial state the bottom left corner of the Window has the 
 * coordinates (0,0). The top right corner of the Window has the coordinates
 * (window-width, - window-height). 
 */
class Window : public sf::RenderWindow
{
public:
  /**
   * @brief Construct a Window
   *
   * Respects configuration options: window-width and window-height.
   * Sets up a sf::View.
   *
   * @param conf A shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as internal key/value pairs.
   */
  explicit Window(boost::shared_ptr<Game::Config> conf);
  ~Window() {}
  
  /**
   * @brief Move the view by given offset
   * @param offset_y Amount of pixels to move y-axis
   */
  void move_view_y(const float offset_y);

private:
  Window(Game::Window const&);
  Window& operator=(Game::Window const&);
  
  /**
   * @brief A shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as internal key/value pairs.
   */
  boost::shared_ptr<Game::Config> config;
};
}

#endif // GAMEWINDOW_H
