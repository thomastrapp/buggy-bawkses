#ifndef GAMEENTITIESBARTENDER_H
#define GAMEENTITIESBARTENDER_H

#include <vector>
#include <ctime>

#include <boost/shared_ptr.hpp>
#include <boost/random.hpp>
#include <boost/random/uniform_real.hpp>

#include <SFML/System.hpp>

#include "Game/Entity.h"
#include "Game/Entities/RectangleDef.h"
#include "Game/Entities/State.h"

namespace Game
{
class World;

namespace Entities
{
class Bar;

/**
 * @brief Manages creation and deletion of Bars
 *
 * The Bartender is responsible for creating new bars and deleting old bars.
 *
 * As the view (=camera) moves upwards new bars need to be added. The Bartender
 * makes sure there's at least bar-pre-fill pixels full of bars on top of the 
 * view. 
 *
 * If a Bar becomes invisible (=it is not shown on the screen) it is deleted.
 */
class Bartender : public Game::Entity 
{
/**
 * @brief A type of vector filled with pointers to Bars
 */
typedef std::vector< boost::shared_ptr<Game::Entities::Bar> > t_map_bars;

public:
/**
 * @brief Construct a Bartender
 *
 * @param conf A shared_ptr to Game::Config, a class that stores user 
 * supplied configuration, as well as internal key/value pairs.
 * @param game_world A reference to the global World, which is a wrapper for 
 * b2World
 */
  Bartender(boost::shared_ptr<Game::Config> conf, Game::World& game_world);
  ~Bartender() {}
  
  /**
   * @brief Update the Bartender
   *
   * New Bars may be created. Old Bars may be deleted.
   *
   * @param view The current view (=camera position)
   */
  State::t_entities_state update(const sf::View& view);
  
  /**
   * @brief Render all child Bars
   *
   * @param renderer The canvas to draw on
   */
  void render(sf::RenderTarget& renderer);

private:
  Bartender(const Bartender&);
  Bartender& operator=(const Bartender&);
  
  /**
   * @brief Adds new Bars if needed
   *
   * As the view (=camera) moves upwards new bars need to be added. The 
   * Bartender makes sure there's at least bar-pre-fill pixels full of bars on 
   * the top of view.
   *
   * @param view The current view (=camera position)
   */
  void _maybe_add_new_bars(const sf::View& view);
  
  /**
   * @brief Remove old Bars if needed
   *
   * If a Bar becomes invisible (=it is not shown on the screen) it gets
   * deleted.
   *
   * @param view The current view (=camera position)
   */
  void _maybe_remove_old_bars(const sf::View& view);
  
  /**
   * @brief Stores a new Bar
   *
   * @param rect_def An instance of RectangleDef defining the size and 
   * position of a Bar
   */
  void _insert_bar(const Game::Entities::RectangleDef& rect_def);
  
  /**
   * @brief A shared_ptr to Game::Config, a class that stores user 
   * supplied configuration, as well as internal key/value pairs.
   */
  boost::shared_ptr<Game::Config> config;
  
  /**
   * @brief A reference to the global World, which is a wrapper for b2World
   */
  Game::World& world;
  
  /**
   * @brief A vector filled with pointers to Bars
   */
  t_map_bars bars;
  
  /**
   * @brief The global y-offset for the next Bar to be placed on
   */
  float next_bar_pos_y;
  
  /**
   * @brief A pseudo random generator
   *
   * The Bar's size and y-position is randomly generated
   */
  boost::mt19937 rand_gen;
};

}
}

#endif // GAMEENTITIESBARTENDER_H
