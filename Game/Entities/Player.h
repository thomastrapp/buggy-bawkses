#ifndef GAMEENTITIESPLAYER_H
#define GAMEENTITIESPLAYER_H

#include <boost/shared_ptr.hpp>

#include "Game/Config.h"
#include "Game/World.h"
#include "Game/Util/Util.h"
#include "Game/Entity.h"
#include "Game/Entities/Id.h"
#include "Game/Entities/FootSensor.h"

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
  ~Player();
  
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
   * and then call Game::Entity::sync_visible to apply any Box2d 
   * transformations to the sfml shape.
   */
  void update(const sf::View& /* view */);
  
  /**
   * @brief Handle user input for player, e.g. jump, run
   *
   * Applies forces to the physics simulation based on user input.
   * Player may only jump if the Player's foot is on ground.
   *
   * @param event The event containing relevant user input
   * @throws Game::Exception
   */
  void handle_input(const sf::Event& input);

private:
  Player(const Player&);
  Player& operator=(const Player&);
  
  /**
   * @brief Helper function to apply velocity based on current_move_state
   *
   * Gradually increase the players speed while the user is pressing arrow 
   * keys. The Player's speed may not exceed player-top-speed.
   * If the user releases an arrow key, the Player's current_move_state 
   * changes to MOVEMENT_STOPPED. The Player's speed is then gradually 
   * decreased.
   */
  void _handle_movement();
  
  /**
   * @brief Helper function to set current_move_state based on key presses
   * @param input An event with event.type KeyPressed
   */
  void _handle_key_press(const sf::Event& input);
  
  /**
   * @brief Helper function to set current_move_state based on key releases
   * @param input An event with event.type KeyReleased
   */
  void _handle_key_release(const sf::Event& input);
  
  /**
   * @brief The t_move_state enum declares all possible values for 
   * current_move_state
   */
  enum t_move_state {
    //MOVEMENT_INVALID = 1 << 0,
    /// The Player has stopped or is stopping
    MOVEMENT_STOPPED = 1 << 1,
    /// The Player moves to the left
    MOVEMENT_LEFT    = 1 << 2,
    /// The Player moves to the right
    MOVEMENT_RIGHT   = 1 << 3
  };
  
  /**
   * @brief A shared_ptr to Game::Config, a class that stores user 
   * supplied configuration, as well as internal key/value pairs.
   */
  boost::shared_ptr<Game::Config> config;

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
  FootSensor foot;
  
  /**
   * @brief The current state of movement
   */
  Player::t_move_state current_move_state; 
};

  }
}

#endif // GAMEENTITIESPLAYER_H
