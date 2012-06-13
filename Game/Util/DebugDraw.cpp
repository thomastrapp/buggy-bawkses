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
