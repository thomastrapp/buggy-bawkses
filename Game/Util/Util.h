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

#ifndef GAMEUTILUTIL_H
#define GAMEUTILUTIL_H

#include <iostream>

#include "Game/Exception.h"
#include "Game/Entities/Id.h"

namespace Game
{
  namespace Util
  {
    /**
     * @brief A large enough pie
     */
    static const float pi = 3.14f;
    
    /**
     * @brief Scale between Box2d (meters) and SFML (pixels)
     */
    static const float pixel_per_meter = 128.0f;
  
    /**
     * @brief Convert pixels to meters
     * @param pixels
     * @return meters
     */
    float pixel_to_meter(const float pixels);
    
    /**
     * @brief Converts meters to pixels
     * @param meters
     * @return pixels
     */
    float meter_to_pixel(const float meters);
    
    /**
     * @brief Convert radians to degrees
     * @param rad radians
     * @return degrees
     */
    float rad_to_deg(const float rad);
  }
}

#endif // GAMEUTILUTIL_H
