#ifndef GAMEENTITIESRECTANGLE_H
#define GAMEENTITIESRECTANGLE_H

#include <boost/shared_ptr.hpp>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Config.h"
#include "Game/Entity.h"
#include "Game/World.h"
#include "Game/Entities/RectangleDef.h"

namespace Game
{
  namespace Entities
  {

/**
 * @brief A static rectangle
 *
 * A sf::RectangleShape combined with a Box2d b2Body.
 * Position is static (cannot be pushed).
 */
class Rectangle : public Game::Entity
{
public:
  /**
   * @brief Construct a static Rectangle
   *
   * @param game_world A reference to the global World, which is a wrapper for 
   * b2World
   * @param rect_def An instance of class RectangleDef, which describes this
   * rectangle
   */
  Rectangle(
    Game::World& game_world,
    const Game::Entities::RectangleDef& rect_def
  );
  ~Rectangle() {}
  
  /**
   * @brief Render this Rectangle
   *
   * @param renderer The canvas to draw on
   */
  void render(sf::RenderTarget& renderer);
  
  /**
   * @brief Update this Rectangle
   */
  void update();

private:
  Rectangle(const Rectangle&);
  Rectangle& operator=(const Rectangle&);

  /**
   * @brief The physical representation of a Rectangle. Memory is owned by 
   * b2World.
   */
  b2Body * physics;
  
  /**
   * @brief The SFML shape, the visible representation of a Rectangle
   */
  sf::RectangleShape visible;
};

  }
}

#endif // GAMEENTITIESRECTANGLE_H
