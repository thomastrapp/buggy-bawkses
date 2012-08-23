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

#include "Game/Util/Util.h"

namespace Game
{
  namespace Util
  {
    float pixel_to_meter(const float pixels)
    {
      return pixels / Game::Util::pixel_per_meter;
    }
    
    float meter_to_pixel(const float meters)
    {
      return meters * Game::Util::pixel_per_meter;
    }
    
    float rad_to_deg(const float rad)
    {
      return rad * 180 / Game::Util::pi;
    }
  }
}
