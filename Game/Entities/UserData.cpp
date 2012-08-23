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

#include "Game/Entities/UserData.h"

// solve circular dependencies
#include "Game/Entity.h"

namespace Game
{
namespace Entities
{
namespace UserData
{

void * to_user_data(Game::Entity * entity)
{
  if( entity == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }

  return static_cast<void *>(entity);
}

Game::Entity * to_entity(void * user_data)
{
  if( user_data == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }
  
  return static_cast<Game::Entity *>(user_data);
}

}
}
}
