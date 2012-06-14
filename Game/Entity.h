#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <boost/shared_ptr.hpp>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Config.h"
#include "Game/World.h"
#include "Game/Util/Util.h"
#include "Game/Entities/Id.h"
 
namespace Game
{

/**
 * @brief Abstract base class for drawable objects
 *
 * An Entity is to be used as a common base class for all objects that are
 * rendered on the screen.
 */
class Entity
{
public:
  /**
   * @brief Construct Entity
   *
   * @param entity_id A distinct Id for this Entity
   */
  Entity(Game::Entities::Id::t_entities_id id);
  
  /**
   * @brief Destruct Entity
   *
   * Declared virtual to allow using Entity as a base class
   */
  virtual ~Entity() {}
  
  /**
   * @brief Render this Entity
   *
   * All subclasses must implement this method.
   *
   * @param renderer The canvas to draw on
   */
  virtual void render(sf::RenderTarget& renderer) = 0;
  
  /**
   * @brief Update this Entity
   *
   * All subclasses must implement this method.
   */
  virtual void update() = 0;
  
  /**
   * @brief To pass user supplied input to a Entity
   *
   * Subclasses may implement this method.
   */
  virtual void handle_input(const sf::Event&)
  {
  }
  
  /**
   * @brief Return a distinct Entity Id
   *
   * @return Entity Id
   */
  Game::Entities::Id::t_entities_id get_entity_id() const;
  
  /**
   * @brief Helper function to apply any Box2d transformations of a 
   * b2Body (source) to an sfml shape (target).
   *
   * Throws a Game::Exception if source is NULL.
   *
   * @param source A pointer to the physical body
   * @param target A reference to the visible shape
   * @throws Game::Exception
   */
  void sync_visible(const b2Body * source, sf::Transformable& target);
  
private:
  Entity(const Entity&);
  Entity& operator=(const Entity&);
  
  const Game::Entities::Id::t_entities_id entity_id;
};

}

#endif // GAMEENTITY_H
