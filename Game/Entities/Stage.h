#ifndef GAMEENTITIESSTAGE_H
#define GAMEENTITIESSTAGE_H

#include <iostream>
#include <boost/shared_ptr.hpp>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Entity.h"
#include "Game/Config.h"
#include "Game/Window.h"
#include "Game/Util/Util.h"
#include "Game/Entities/Rectangle.h"
#include "Game/Entities/RectangleDef.h"

namespace Game 
{
  namespace Entities
  {

/**
 * @brief A stage that encloses the screen.
 *
 * A stage has three Retangles:
 * - A wall to the left
 * - A bottom ground
 * - A wall to the right
 *
 * These Rectangles form a U-like shape to enclose a stage.
 */
class Stage : public Game::Entity
{
public:
  /**
   * @brief Construct a stage
   *
   * @param conf A shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as hardcoded key/value pairs.
   * @param game_world A reference to the global World, which is a wrapper for 
   * b2World
   */
  Stage(boost::shared_ptr<Game::Config> conf, Game::World& game_world);
  ~Stage() {}
  
  /**
   * @brief Render this stage
   *
   * Render all Rectangles: left, bottom, right.
   *
   * @param renderer The canvas to draw on
   */
  void render(sf::RenderTarget& renderer);
  
  /**
   * @brief Update this stage.
   */
  void update();

private:
  Stage(const Stage&);
  Stage& operator=(const Stage&);

  /**
   * @brief A shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as hardcoded key/value pairs.
   */
  boost::shared_ptr<Game::Config> config;
  
  /**
   * @brief A reference to the global World, which is a wrapper for b2World
   */
  Game::World& world;
  
  /**
   * @brief The left wall
   */
  Game::Entities::Rectangle left;
  
  /**
   * @brief The bottom ground
   */
  Game::Entities::Rectangle bottom;
  
  /**
   * @brief The right wall
   */
  Game::Entities::Rectangle right;
};

  }
}

#endif // GAMEENTITIESSTAGE_H
