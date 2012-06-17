#ifndef GAMEENTITIESPLAYERFOOT_H
#define GAMEENTITIESPLAYERFOOT_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Entity.h"
#include "Game/Entities/UserData.h"

namespace Game
{
namespace Entities
{

/**
 * @brief Listens on collisions of the Player's foot
 *
 * The CollisionDispatcher will call begin_collision and end_collision of this
 * entity. This class then increments/decrements a private member if the 
 * Player's foot was subject to the collision.
 * 
 * E.g. the method is_ground() can then be used to determine whether the player
 * is able to jump.
 */
class PlayerFoot : public Entity
{
public:
  PlayerFoot();
  ~PlayerFoot() {}
  
  /**
   * @brief Add a foot to a body
   *
   * Throws a Game::Exception if body is NULL.
   *
   * @param body A b2Body
   * @param body_size A vector describing the players width and height
   * @throws Game::Exception
   */
  void bind_to_body(b2Body * body, const sf::Vector2f body_size);
  
  /**
   * @brief Record start of collisions
   *
   * Increments private member foot_contacts.
   */
  void begin_collision(b2Contact * /* contact */);

  /**
   * @brief Record end of collisions
   *
   * Decrements private member foot_contacts.
   */
  void end_collision(b2Contact * /* contact */);
  
  /**
   * @brief Check if this Entity is on ground
   *
   * If true, the foot is currently colliding with solid ground, 
   * meaning begin_collision recorded more collisions with solid ground than 
   * end_collision.
   *
   * @return true if PlayerFoot is on ground
   */
  bool is_on_ground();
  
  /**
   * @brief Fullfill entity
   *
   * The PlayerFoot is not visible, so nothing is rendered.
   */
  void render(sf::RenderTarget& /* renderer */) {}

private:
  PlayerFoot(const PlayerFoot&);
  PlayerFoot& operator=(const PlayerFoot&);
  
  int foot_contacts;
};

}
}

#endif // GAMEENTITIESPLAYERFOOT_H
