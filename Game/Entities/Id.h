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

#ifndef GAMEENTITIESID_H
#define GAMEENTITIESID_H

#include <cstddef>

#include "Game/Exception.h"

namespace Game
{
  namespace Entities
  {
    /**
     * @brief Entity Ids.
     */
    namespace Id 
    {
      /**
       * @brief The t_entities_id enum defines constants for Entity Ids.
       */
      enum t_entities_id
      {
        //INVALID     = 1 << 0, 
        PLAYER      = 1 << 1, 
        FOOT_SENSOR = 1 << 2,
        WALL_LEFT   = 1 << 3,
        WALL_RIGHT  = 1 << 4,
        BARTENDER   = 1 << 5,
        BAR         = 1 << 6
      };
    }
  }
}

#endif // GAMEENTITIESID_H
