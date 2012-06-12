#ifndef GAMEUTILDEBUGDRAW_H
#define GAMEUTILDEBUGDRAW_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Util/Util.h"

namespace Game
{
namespace Util
{
class DebugDraw : public b2Draw
{
public:
  DebugDraw(sf::RenderTarget& renderer);
  ~DebugDraw() {}
  
  void DrawPolygon(const b2Vec2*, int32, const b2Color &)
  {
    std::cout << "DebugDraw::DrawPolygon(..) NOT IMPLEMENTED" << std::endl;
  }
  
  void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &);
  
  void DrawCircle(const b2Vec2&, float32, const b2Color&)
  {
    std::cout << "DebugDraw::DrawCircle(..) NOT IMPLEMENTED" << std::endl;
  }
  
  void DrawSolidCircle(const b2Vec2 &, float32, const b2Vec2&, const b2Color&)
  {
    std::cout << "DebugDraw::DrawSolidCircle(..) NOT IMPLEMENTED" << std::endl;
  }
  
  void DrawSegment(const b2Vec2&, const b2Vec2&, const b2Color&)
  {
    std::cout << "DebugDraw::DrawSegment(..) NOT IMPLEMENTED" << std::endl;
  }
  
  void DrawTransform(const b2Transform&)
  {
    std::cout << "DebugDraw::DrawTransform(..)" << std::endl;
  }
  
private:
  DebugDraw(const DebugDraw&);
  DebugDraw& operator=(const DebugDraw&);
  
  sf::RenderTarget& renderer;
};
}
}

#endif // GAMEUTILDEBUGDRAW_H
