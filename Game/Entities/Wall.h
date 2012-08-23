/*
  This file is part of the "Buggy Bawkses" Project.

  Copyright (C) 2012 Thomas Trapp; mailto: bawkses@thomastrapp.com

  "Buggy Bawkses" is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, 
  Boston, MA  02110-1301, USA.

  See COPYING for details.
*/

#ifndef GAMEENTITIESWALL_H
#define GAMEENTITIESWALL_H

#include <boost/shared_ptr.hpp>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Config.h"
#include "Game/Entity.h"
#include "Game/Entities/RectangleDef.h"
#include "Game/Entities/State.h"

namespace Game
{
  class World;
namespace Entities
{

/**
 * @brief A static Wall
 *
 * A sf::RectangleShape combined with a Box2d b2Body.
 * Position is static (cannot be pushed).
 */
class Wall : public Game::Entity
{
public:
  /**
   * @brief Construct a static Wall
   *
   * @param game_world A reference to the global World, which is a wrapper for 
   * b2World
   * @param rect_def An instance of class WallDef, which describes this
   * Wall
   */
  Wall(
    Game::Entities::Id::t_entities_id entity_id,
    Game::World& game_world,
    const Game::Entities::RectangleDef& rect_def
  );
  ~Wall();
  
  /**
   * @brief Render this Wall
   *
   * @param renderer The canvas to draw on
   */
  void render(sf::RenderTarget& renderer);
  
  /**
   * @brief Update this Wall
   *
   * The y-position of the Wall is kept in sync with the views y-position.
   * This moves the Walls upwards with the camera.
   *
   * @param view The current view (=camera)
   */
  State::t_entities_state update(const sf::View& view);

private:
  Wall(const Wall&);
  Wall& operator=(const Wall&);

  /**
   * @brief The physical representation of a Wall. Memory is owned by 
   * b2World.
   */
  b2Body * physics;
  
  /**
   * @brief The SFML shape, the visible representation of a Wall
   */
  sf::RectangleShape visible;
};

}
}

#endif // GAMEENTITIESWALL_H
