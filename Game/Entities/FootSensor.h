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

#ifndef GAMEENTITIESFOOTSENSOR_H
#define GAMEENTITIESFOOTSENSOR_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "Game/Entity.h"
#include "Game/Entities/UserData.h"

namespace Game
{
namespace Entities
{

/**
 * @brief A sensor for collisions on the bottom of b2Body's
 *
 * The CollisionDispatcher will call begin_collision and end_collision of this
 * entity. This class then increments/decrements a private member if the 
 * foot was subject to the collision.
 * 
 * E.g. the method is_on_ground() can then be used to determine if a player
 * is able to jump.
 */
class FootSensor : public Entity
{
public:
  FootSensor();
  ~FootSensor() {}
  
  /**
   * @brief Add this foot sensor to a body
   *
   * Throws a Game::Exception if body is NULL.
   *
   * @param body A b2Body
   * @param body_size A vector describing the body's width and height
   * @throws Game::Exception
   */
  void bind_to_body(b2Body * body, const sf::Vector2f body_size);
  
  /**
   * @brief Record start of collisions
   *
   * Increments private member contacts.
   */
  void begin_collision(b2Contact * /* contact */);

  /**
   * @brief Record end of collisions
   *
   * Decrements private member contacts.
   */
  void end_collision(b2Contact * /* contact */);
  
  /**
   * @brief Check if this Entity is on ground
   *
   * If true, the foot is currently colliding with solid ground, 
   * meaning begin_collision recorded more collisions with solid ground than 
   * end_collision.
   *
   * @return true if foot is on ground
   */
  bool is_on_ground();
  
  /**
   * @brief Fullfill entity
   *
   * A FootSensor is not visible, so nothing is rendered.
   */
  void render(sf::RenderTarget& /* renderer */) {}

private:
  FootSensor(const FootSensor&);
  FootSensor& operator=(const FootSensor&);
  
  int contacts;
};

}
}

#endif // GAMEENTITIESFOOTSENSOR_H
