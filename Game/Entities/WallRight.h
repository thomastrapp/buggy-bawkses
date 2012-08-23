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

#ifndef GAMEENTITIESWALLRIGHT_H
#define GAMEENTITIESWALLRIGHT_H

#include "Game/Entities/Wall.h"

namespace Game
{
namespace Entities
{

/**
 * @brief Enclosing the game to the right
 */
class WallRight : public Wall
{
public:
  /**
   * @brief Construct a right Wall
   *
   * A concrete implementation of a Wall
   *
   * @param conf A shared_ptr to Game::Config, a class that stores user 
   * supplied configuration, as well as internal key/value pairs.
   * @param game_world A reference to the global World, which is a wrapper for 
   * b2World
   */
  WallRight(boost::shared_ptr<Game::Config> conf, Game::World& game_world);
  ~WallRight() {}
  
private:
  WallRight(const WallRight&);
  WallRight& operator=(const WallRight&);
};

}
}


#endif // GAMEENTITIESWALLRIGHT_H
