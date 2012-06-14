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
 * build a static Wall of specified size (WallDef::size), 
 * position (WallDef::pos) and Entity Id (WallDef::entity_id).
 */
class WallDef
{
public:
  /**
   * @brief Construct a WallDef
   *
   * @param wall_size The total size of the Wall: width (x) and length (y)
   * @param wall_pos The global position of the Wall on the stage
   * @param id The distinct Entity Id of the Wall
   */
  WallDef(
    const sf::Vector2f& wall_size, 
    const sf::Vector2f& wall_pos,
    Game::Entities::Id::t_entities_id id
  )
  : size(wall_size),
    pos(wall_pos),
    entity_id(id)
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
  
  /**
   * @brief The Wall's Entity Id
   */
  const Game::Entities::Id::t_entities_id entity_id;

private:
  WallDef(const WallDef&);
  WallDef& operator=(const WallDef&);
};

  }
}

#endif // GAMEENTITIESWALLDEF_H
