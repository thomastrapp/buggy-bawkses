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

#include "Game/Window.h"

namespace Game
{

Window::Window(boost::shared_ptr<Game::Config> conf)
: sf::RenderWindow
  (
    sf::VideoMode
    (
      static_cast<unsigned int>(conf->get<int>("window-width")), 
      static_cast<unsigned int>(conf->get<int>("window-height"))
    ),
    conf->get<std::string>("window-title")
  ),
  config(conf)
{
  sf::View view(
    sf::FloatRect(
      0.0f,
      -1.0f * static_cast<float>(conf->get<int>("window-height")),
      static_cast<float>(conf->get<int>("window-width")), 
      static_cast<float>(conf->get<int>("window-height"))
    )
  );
  this->setView(view); 
  this->setVerticalSyncEnabled(true);
  this->setKeyRepeatEnabled(false);
}

void Window::move_view_y(const float offset_y)
{
  sf::View view = this->getView();
  view.move(0.0f, offset_y);
  this->setView(view);
}

}
