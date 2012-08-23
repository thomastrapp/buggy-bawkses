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

#ifndef GAMEENTITIESUSERDATA_H
#define GAMEENTITIESUSERDATA_H

#include <boost/exception.hpp>

#include "Game/Exception.h"

namespace Game
{
  class Entity;
  
namespace Entities
{
/**
 * @brief Functions to convert from and to b2Fixture user data.
 */
namespace UserData
{

  /**
   * @brief Convert an Entity pointer to b2Fixture user data.
   *
   * Helper function to convert between Entity and void pointer.
   * Throws Game::Exception if entity is NULL.
   *
   * @param entity A pointer to a Game::Entity
   * @return An void pointer, whose address equals passed
   * parameter entity
   * @throws Game::Exception
   */
  void * to_user_data(Game::Entity * entity);
  
  /**
   * @brief Convert b2Fixture user data to a Entity pointer
   *
   * Helper function to convert between void pointer and Entity pointer.
   * Throws Game::Exception if user_data is NULL.
   *
   * @param user_data
   * @return A pointer to a Game::Entity
   * @throws Game::Exception
   */
  Game::Entity * to_entity(void * user_data);

}
}
}

#endif // GAMEENTITIESUSERDATA_H
