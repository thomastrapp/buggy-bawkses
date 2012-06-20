#ifndef GAMEENTITIESBAR_H
#define GAMEENTITIESBAR_H

#include <Box2D/Box2D.h>

#include "Game/World.h"
#include "Game/Entities/RectangleDef.h"
#include "Game/Entity.h"

namespace Game
{
  // solve circular dependencies
  class World;
  
namespace Entities
{

/**
 * @brief A static platform the Player can jump on
 *
 * A Bar is only solid when the Player comes from above. If the Player jumps up
 * to the Bar, he may pass, but cannot descend downwards through the Bar.
 */
class Bar : public Entity
{
public:
  /**
   * @brief Construct a Bar
   *
   * @param conf A shared_ptr to Game::Config, a class that stores user 
   * supplied configuration, as well as internal key/value pairs.
   * @param game_world A reference to the global World, which is a wrapper for 
   * b2World
   * @param rect_def An instance of class RectangleDef, which describes this
   * Bar
   */
  Bar(
    boost::shared_ptr<Game::Config> conf, 
    Game::World& game_world, 
    const RectangleDef& rect_def
  );
  ~Bar();
  
  /**
   * @brief Render this Bar
   *
   * @param renderer The canvas to draw on
   */
  void render(sf::RenderTarget& renderer);
  
  /**
   * @brief Callback for CollisionDispatcher
   *
   * This function is called after collision detection, but before collision
   * resolution. 
   * We use this function to implement a one-way collision:
   * * If the player jumps up to a Bar then he may pass (collision off), but
   * * The player can stand/land on a Bar (collision on)
   *
   * @param contact The collision information
   */
  void pre_solve_collision(
    b2Contact * contact, 
    const b2Manifold * /* old_manifold */
  );
  
  bool is_in_view(const sf::View& view);

private:
  Bar(const Bar&);
  Bar& operator=(const Bar&);
  
  /**
   * @brief A shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as internal key/value pairs.
   */
  boost::shared_ptr<Game::Config> config;
  
  /**
   * @brief The physical representation of a Bar. Memory is owned by 
   * b2World.
   */
  b2Body * physics;
  
  /**
   * @brief The SFML shape, the visible representation of a Bar
   */
  sf::RectangleShape visible;
  
  /**
   * @brief The height of this bar
   */
  const float height;
};

}
}

#endif // GAMEENTITIESBAR_H
