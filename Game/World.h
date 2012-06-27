#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>

#include <boost/foreach.hpp>
#include <boost/shared_ptr.hpp>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game/Window.h"
#include "Game/Config.h"
#include "Game/CollisionDispatcher.h"
#include "Game/Entities/RectangleDef.h"
#include "Game/Entities/Bar.h"
#include "Game/Entities/Bartender.h"

namespace Game
{
  // Forward declaration to solve circular dependency between World and Entity
  class Entity;
  
  /**
   * @brief A vector-type containing elements of type Entity
   */
  typedef std::vector< boost::shared_ptr<Game::Entity> > t_entities;

  /**
   * @brief Acts as a Wrapper for b2World and creates all entities.
   *
   * A call to World::render or World::update is proxied to all child entities.
   *
   * The World's coordinate space starts at 0 (bottom of the World) and grows 
   * upwards into negativity.
   *
   * The reader may consider this drawing as a substitute for this bad 
   * explanation:
   * 
   * -1 ^
   *    | ->visible coordinate space<-
   *  0 +-------------------------------> +1
   *    0
   */
  class World
  {
  public:
    /**
     * @brief Construct a World
     *
     * @param conf A shared_ptr to Game::Config, a class that stores user 
     * supplied configuration, as well as internal key/value pairs.
     */
    explicit World(boost::shared_ptr<Game::Config> conf);
    ~World() {}
    
    /**
     * @brief Step the world
     */
    void step();
    
    /**
     * @brief Render all child entities
     *
     * @param renderer The canvas to draw on
     */
    void render(sf::RenderTarget& renderer);
    
    /**
     * @brief Update all child entities
     */
    void update(const sf::View& view);
    
    /**
     * @brief Handle input
     *
     * @param event 
     */
    void handle_input(const sf::Event& input);
    
    /**
     * @brief Return a shared_pointer to a Box2d b2World
     *
     * Since b2World is not intended to be used as a public base class (e.g. no
     * virtual destructor), we let any caller have access to it.
     *
     * @return boost::shared_ptr<b2World> A shared pointer to b2World
     */
    boost::shared_ptr<b2World> b2world() const;
    
  private:
    World(Game::World const&);
    World& operator=(Game::World const&);
    
    /**
     * @brief Bring entities to life
     */
    void _setup_entities();
    
    /**
     * @brief A shared_ptr to a Box2d b2World
     */
    boost::shared_ptr<b2World> b2_world;
    
    /**
     * @brief A shared_ptr to Game::Config, a class that stores user supplied
     * configuration, as well as internal key/value pairs.
     */
    boost::shared_ptr<Game::Config> config;

    /**
     * @brief A vector filled with entities
     */
    t_entities entities;
    
    /**
     * @brief Dispatches collision events to entities
     */
    CollisionDispatcher cdispatcher;
  };
}

#endif // GAMEWORLD_H
