#ifndef GAMEENTITIESRECTANGLEDEF_H
#define GAMEENTITIESRECTANGLEDEF_H

#include <SFML/Graphics.hpp>

namespace Game
{
namespace Entities
{

class RectangleDef
{
public:
  RectangleDef(const sf::Vector2f& rect_size, const sf::Vector2f& rect_pos)
  : size(rect_size),
    pos(rect_pos)
  {
  }

  const sf::Vector2f size;
  const sf::Vector2f pos;

private:
  RectangleDef(const RectangleDef&);
  RectangleDef& operator=(const RectangleDef&);
};

  }
}

#endif // GAMEENTITIESRECTANGLEDEF_H
