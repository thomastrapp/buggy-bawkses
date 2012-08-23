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

#ifndef GAMEUTILDEBUGDRAW_H
#define GAMEUTILDEBUGDRAW_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Util/Util.h"

namespace Game
{
/**
 * @brief Various utility functions and constants.
 */
namespace Util
{

/**
 * @brief DebugDraw draws the physical representation of Box2d objects.
 *
 * To help with debugging this utility class outlines all Box2d shapes.
  *
 * Any use of a DebugDraw object must respect the preprocessor define 
 * ENABLE_DEBUG_DRAW, e.g.: 
 * @code
 * #ifdef ENABLE_DEBUG_DRAW
 *   DebugDraw drawer(..);
 * #endif
 * @endcode
 */
class DebugDraw : public b2Draw
{
public:
  /**
   * @brief Construct a DebugDraw
   *
   * @param renderer The canvas to draw on
   */
  explicit DebugDraw(sf::RenderTarget& renderer);
  ~DebugDraw() {}
 
  /**
   * @brief Draw a polygon
   *
   * Draws the outline of a polygon 
   *
   * @param vertices The vertices that form the shape
   * @param vertexCount The number of elements in vertices
   */
  void DrawSolidPolygon(
    const b2Vec2 *vertices, 
    int32 vertexCount, 
    const b2Color &
  );
   
  /**
   * @brief NOT IMPLEMENTED
   */
  void DrawPolygon(const b2Vec2*, int32, const b2Color &)
  {
    std::cout << "DebugDraw::DrawPolygon(..) NOT IMPLEMENTED" << std::endl;
  }

  /**
   * @brief NOT IMPLEMENTED
   */
  void DrawCircle(const b2Vec2&, float32, const b2Color&)
  {
    std::cout << "DebugDraw::DrawCircle(..) NOT IMPLEMENTED" << std::endl;
  }
  
  /**
   * @brief NOT IMPLEMENTED
   */
  void DrawSolidCircle(const b2Vec2 &, float32, const b2Vec2&, const b2Color&)
  {
    std::cout << "DebugDraw::DrawSolidCircle(..) NOT IMPLEMENTED" << std::endl;
  }
  
  /**
   * @brief NOT IMPLEMENTED
   */
  void DrawSegment(const b2Vec2&, const b2Vec2&, const b2Color&)
  {
    std::cout << "DebugDraw::DrawSegment(..) NOT IMPLEMENTED" << std::endl;
  }
  
  /**
   * @brief NOT IMPLEMENTED
   */
  void DrawTransform(const b2Transform&)
  {
    std::cout << "DebugDraw::DrawTransform(..) NOT IMPLEMENTED" << std::endl;
  }
  
private:
  DebugDraw(const DebugDraw&);
  DebugDraw& operator=(const DebugDraw&);
  
  /**
   * @brief A reference to the canvas to draw on. 
   */
  sf::RenderTarget& renderer;
};
}
}

#endif // GAMEUTILDEBUGDRAW_H
