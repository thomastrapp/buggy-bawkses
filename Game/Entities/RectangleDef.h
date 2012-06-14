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
 * An instance of RectangleDef is passed to the constructor of Rectangle to
 * build a static Rectangle of specified size (RectangleDef::size), 
 * position (RectangleDef::pos), friction (RectangleDef::friction) and
 * Entity Id (RectangleDef::entity_id)
 */
class RectangleDef
{
public:
  /**
   * @brief Construct a RectangleDef
   *
   * @param rect_size The total size of the Rectangle: width (x) and length (y)
   * @param rect_pos The global position of the Rectangle on the stage
   * @param id The distinct Entity Id of the Rectangle
   */
  RectangleDef(
    const sf::Vector2f& rect_size, 
    const sf::Vector2f& rect_pos,
    float rect_friction,
    Game::Entities::Id::t_entities_id id
  )
  : size(rect_size),
    pos(rect_pos),
    friction(rect_friction),
    entity_id(id)
  {
  }

  /**
   * @brief The total size of the Rectangle: width (x) and length (y)
   */
  const sf::Vector2f size;
  
  /**
   * @brief The global position of the Rectangle on the stage
   */
  const sf::Vector2f pos;
  
  /**
   * @brief The Rectangle's friction
   */
  const float friction;
  
  /**
   * @brief The Rectangle's Entity Id
   */
  const Game::Entities::Id::t_entities_id entity_id;

private:
  RectangleDef(const RectangleDef&);
  RectangleDef& operator=(const RectangleDef&);
};

  }
}

#endif // GAMEENTITIESRECTANGLEDEF_H
