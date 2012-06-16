#ifndef GAMEENTITIESWALLDEF_H
#define GAMEENTITIESWALLDEF_H

#include <SFML/Graphics.hpp>

#include "Game/Entities/Id.h"

namespace Game
{
namespace Entities
{

/**
 * @brief A helper class that defines a position and size for a Wall.
 * 
 * An instance of WallDef is passed to the constructor of Wall to
 * build a static Wall of specified size (WallDef::size) and
 * position (WallDef::pos).
 */
class WallDef
{
public:
  /**
   * @brief Construct a WallDef
   *
   * @param wall_size The total size of the Wall: width (x) and length (y)
   * @param wall_pos The global position of the Wall on the stage
   */
  WallDef(
    const sf::Vector2f& wall_size, 
    const sf::Vector2f& wall_pos
  )
  : size(wall_size),
    pos(wall_pos)
  {
  }

  /**
   * @brief The total size of the Wall: width (x) and length (y)
   */
  const sf::Vector2f size;
  
  /**
   * @brief The global position of the Wall on the stage
   */
  const sf::Vector2f pos;

private:
  WallDef(const WallDef&);
  WallDef& operator=(const WallDef&);
};

  }
}

#endif // GAMEENTITIESWALLDEF_H
