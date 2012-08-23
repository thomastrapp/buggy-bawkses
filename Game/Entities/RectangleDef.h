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

#ifndef GAMEENTITIESRECTANGLEDEF_H
#define GAMEENTITIESRECTANGLEDEF_H

#include <SFML/Graphics.hpp>

namespace Game
{
namespace Entities
{

/**
 * @brief A helper class that defines a position and size for a Rectangle.
 * 
 * A RectangleDef defines a rectangle.
 */
class RectangleDef
{
public:
  /**
   * @brief Construct a RectangleDef
   *
   * @param rect_size The total size of a rectangle: width (x) and length
   * (y)
   * @param rect_pos The global position of the Rectangle on the stage
   */
  RectangleDef(
    const sf::Vector2f& rect_size, 
    const sf::Vector2f& rect_pos
  )
  : size(rect_size),
    pos(rect_pos)
  {
  }

  /**
   * @brief The total size of a rectangle: width (x) and length (y)
   */
  const sf::Vector2f size;
  
  /**
   * @brief The global position of a rectangle on the stage
   */
  const sf::Vector2f pos;

private:
  RectangleDef(const RectangleDef&);
  RectangleDef& operator=(const RectangleDef&);
};

  }
}

#endif // GAMEENTITIESRECTANGLEDEF_H
