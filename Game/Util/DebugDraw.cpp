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

#include "Game/Util/DebugDraw.h"

namespace Game
{
namespace Util
{
  DebugDraw::DebugDraw(sf::RenderTarget& render_target)
  : renderer(render_target)
  {
    // Tell box2d to draw solid shapes
    this->SetFlags(b2Draw::e_shapeBit);
  }
  
  void DebugDraw::DrawSolidPolygon(
    const b2Vec2 *vertices, int32 vertexCount, const b2Color &
  )
  {
    sf::VertexArray solid_polygon;
    
    // All points in VertexArray shall be treated as connected corners
    solid_polygon.setPrimitiveType(sf::LinesStrip);
    
    for(int i = 0; i < vertexCount; ++i)
    {
      const sf::Vertex vert(
        sf::Vector2f(
          Game::Util::meter_to_pixel((vertices + i)->x),
          Game::Util::meter_to_pixel((vertices + i)->y)
        ),
        sf::Color(234, 0, 255)
      );
      
      solid_polygon.append(vert);
    }
    
    // connect last corners to close the shape
    const sf::Vertex vert(
      sf::Vector2f(
        Game::Util::meter_to_pixel((vertices)->x),
        Game::Util::meter_to_pixel((vertices)->y)
      ),
      sf::Color(234, 0, 255)
    );
    
    solid_polygon.append(vert);
    
    this->renderer.draw(solid_polygon);
  }
}
}
