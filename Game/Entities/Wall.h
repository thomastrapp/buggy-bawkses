#ifndef GAMEENTITIESWALL_H
#define GAMEENTITIESWALL_H

#include <boost/shared_ptr.hpp>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Config.h"
#include "Game/Entity.h"
#include "Game/Entities/RectangleDef.h"

namespace Game
{
namespace Entities
{

/**
 * @brief A static Wall
 *
 * A sf::RectangleShape combined with a Box2d b2Body.
 * Position is static (cannot be pushed).
 */
class Wall : public Game::Entity
{
public:
  /**
   * @brief Construct a static Wall
   *
   * @param game_world A reference to the global World, which is a wrapper for 
   * b2World
   * @param rect_def An instance of class WallDef, which describes this
   * Wall
   */
  Wall(
    Game::World& game_world,
    const Game::Entities::RectangleDef& rect_def
  );
  ~Wall() {}
  
  /**
   * @brief Render this Wall
   *
   * @param renderer The canvas to draw on
   */
  void render(sf::RenderTarget& renderer);

private:
  Wall(const Wall&);
  Wall& operator=(const Wall&);

  /**
   * @brief The physical representation of a Wall. Memory is owned by 
   * b2World.
   */
  b2Body * physics;
  
  /**
   * @brief The SFML shape, the visible representation of a Wall
   */
  sf::RectangleShape visible;
};

}
}

#endif // GAMEENTITIESWALL_H
