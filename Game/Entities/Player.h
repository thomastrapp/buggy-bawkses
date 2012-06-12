#ifndef GAMEENTITIESPLAYER_H
#define GAMEENTITIESPLAYER_H

#include <boost/shared_ptr.hpp>

#include "Game/Config.h"
#include "Game/World.h"
#include "Game/Util/Util.h"
#include "Game/Entity.h"
#include "Game/Entities/Type.h"

namespace Game
{
  namespace Entities
  {
  
/**
 * @brief A user controllable Entity
 *
 */
class Player : public Game::Entity
{
  /**
   * @brief Listens on collisions of the Player's foot
   *
   * Box2d calls BeginContact and EndContact of this class, when a fixture 
   * has contact to another fixture. This class then increments/decrements 
   * a private member if the Player's foot was subject to the collision.
   * 
   * E.g. the method is_foot_on_ground() can then be used to determine whether 
   * the player is able to jump.
   *
   */
  class FootContactListener : public b2ContactListener
  {
    public:
      FootContactListener();
      ~FootContactListener() {}
      
      /**
       * @brief Record start of collisions
       *
       * Increments private member foot_contacts if any of the fixtures subject to 
       * this collision are the Player's foot (fixtures marked PLAYER_FOOT).
       *
       * @param contact Contains pointers to two b2fixtures that are subject to this
       * collision
       *
       * @throws Game::Exception on parameter contact == NULL
       */
      void BeginContact(b2Contact* contact);

      /**
       * @brief Record end of collisions
       *
       * Decrements private member foot_contacts if any of the fixtures subject to 
       * this collision are the Player's foot (fixtures marked PLAYER_FOOT).
       *
       * @param contact Contains pointers to two b2fixtures that are subject to this
       * collision
       *
       * @throws Game::Exception on parameter contact == NULL
       */
      void EndContact(b2Contact* contact);
      
      /**
       * @brief Check if Player's foot is on ground
       *
       * If true, the Player's foot is currently colliding with solid ground, 
       * meaning BeginContact recorded more collisions with solid ground than 
       * End Contact.
       *
       * @return true if Player is on ground
       */
      bool is_foot_on_ground();
            
    private:
      FootContactListener(const FootContactListener&);
      FootContactListener& operator=(const FootContactListener&);
      
      /**
       * @brief Check if a b2Fixture is the Player's foot
       *
       * Checks if given fixture is marked PLAYER_FOOT.
       *
       * @param fixture A non NULL fixture
       * @return true if fixture's user data is PLAYER_FOOT
       * @throws Game::Exception on parameter fixture == NULL
       */
      bool _fixture_is_player_foot(b2Fixture* fixture);
      
      /**
       * @brief A counter that is incremented/decremented when
       * BeginContact()/EndContact() is called
       */
      unsigned int foot_contacts;
  };

public:
  /**
   * @brief Construct a new Player
   *
   * @param conf shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as hardcoded key/value pairs.
   * @param game_world reference to the global World, which is a wrapper for 
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
   *
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
   * @brief The physical representation of a Player
   */
  b2Body * physics;
  /**
   * @brief The visual representation of a Player
   */
  sf::RectangleShape visible;
  
  /**
   * @brief A helper class to determine whether the Player can jump
   */
  FootContactListener foot_sensor;
};

  }
}

#endif // GAMEENTITIESPLAYER_H
