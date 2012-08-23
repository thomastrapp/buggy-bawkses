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

#ifndef GAMECOLLISIONDISPATCHER_H
#define GAMECOLLISIONDISPATCHER_H

#include <boost/exception.hpp>

#include <Box2D/Box2D.h>

#include "Game/Exception.h"
#include "Game/Entities/UserData.h"

namespace Game
{

/**
 * @brief Notifies Entities about collisions
 *
 * 1. If a collision happens, Box2D calls the CollisionDispatcher.
 * 2. The CollisionDispatcher then tries to identify the participating 
 * Entities.
 * 3. If an Entity stores a pointer to itself in a b2Fixture's user data,
 * it will get notified.
 * 4. The Entity is then able to take apropriate action. For Example, the 
 * Entity may count the amount of collisions (PlayerFoot) or disable the
 * collsion (Bar).
 */
class CollisionDispatcher : public b2ContactListener
{
public:
  CollisionDispatcher() {}
  ~CollisionDispatcher() {}
  
  /**
   * @brief Record start of collisions
   *
   * Notifies all Entities that are participants in this collision.
   * Pointers to Entities are taken from the b2Fixture's user data.
   *
   * Throws Game::Exception if contact is NULL.
   *
   * @param contact Contains pointers to two b2fixtures that are subject to
   * this collision
   * @throws Game::Exception
   */
  void BeginContact(b2Contact* contact);

  /**
   * @brief Record end of collisions
   *
   * Notifies all Entities that are participants in this collision.
   * Pointers to Entities are taken from the b2Fixture's user data.
   *
   * Throws Game::Exception if contact is NULL.
   *
   * @param contact Contains pointers to two b2fixtures that are subject to 
   * this collision
   * @throws Game::Exception
   */
  void EndContact(b2Contact* contact);
  
  /**
   * @brief Callback for pre solving of collisions
   *
   * @param contact Contains pointers to two b2fixtures that are subject to 
   * this collision
   * @param old_manifold
   */
  void PreSolve(b2Contact* contact, const b2Manifold* old_manifold);
  //void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
  
private:
  CollisionDispatcher(const CollisionDispatcher&);
  CollisionDispatcher& operator=(const CollisionDispatcher&);
};


}

#endif // GAMECOLLISIONDISPATCHER_H
