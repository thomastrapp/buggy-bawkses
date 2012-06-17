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
