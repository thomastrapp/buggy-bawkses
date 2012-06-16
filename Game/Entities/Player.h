#ifndef GAMEENTITIESPLAYER_H
#define GAMEENTITIESPLAYER_H

#include <boost/shared_ptr.hpp>

#include "Game/Config.h"
#include "Game/World.h"
#include "Game/Util/Util.h"
#include "Game/Entity.h"
#include "Game/Entities/Id.h"
#include "Game/Entities/PlayerFoot.h"

namespace Game
{
  /**
   * @brief Everything related to entities
   */
  namespace Entities
  {
  
/**
 * @brief A user controllable Entity
 */
class Player : public Game::Entity
{

public:
  /**
   * @brief Construct a new Player
   *
   * @param conf A shared_ptr to Game::Config, a class that stores user 
   * supplied configuration, as well as internal key/value pairs.
   * @param game_world A reference to the global World, which is a wrapper for 
   * b2World
   */
  Player(boost::shared_ptr<Game::Config> conf, Game::World& game_world);
  ~Player() {}
  
  /**
   * @brief Render this Player
   *
   * @param renderer The canvas to draw on
   */
  void render(sf::RenderTarget& renderer);
  
  /**
   * @brief Update Player logic
   *
   * Update the Player logic ("tick")
   * and then call Game::Entity::sync_visible to apply any Box2d transformations
   * to the sfml shape.
   */
  void update();
  
  /**
   * @brief Handle user input for player, e.g. jump, run
   *
   * Applies forces to the physics simulation based on user input.
   * Player may only jump if the Player's foot is on ground.
   *
   * @param event event.type must equal sf::Event::KeyPressed
   * @throws Game::Exception
   */
  void handle_input(const sf::Event& event);

private:
  Player(const Player&);
  Player& operator=(const Player&);

  /**
   * @brief The physical representation of a Player. Memory is owned by 
   * b2World.
   */
  b2Body * physics;
  
  /**
   * @brief The SFML shape, the visual representation of a Player
   */
  sf::RectangleShape visible;
  
  /**
   * @brief A helper class to determine whether the Player can jump
   */
  PlayerFoot foot;
};

  }
}

#endif // GAMEENTITIESPLAYER_H
