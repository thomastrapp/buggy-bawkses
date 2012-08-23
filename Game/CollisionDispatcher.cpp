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

#include "Game/CollisionDispatcher.h"

// solve circular dependencies
#include "Game/Entity.h"

namespace Game
{

/*
 * TODO: Respect DRY
 * maybe even use boost::function
 */ 

void CollisionDispatcher::BeginContact(b2Contact * contact)
{
  if( contact == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }

  b2Fixture * fixtureA = contact->GetFixtureA();
  b2Fixture * fixtureB = contact->GetFixtureB();
  
  void * user_dataA = fixtureA->GetUserData();
  void * user_dataB = fixtureB->GetUserData();
  
  if( user_dataA != NULL )
  {
    Game::Entity * entity = Game::Entities::UserData::to_entity(user_dataA);
    entity->begin_collision(contact);
  }
  
  if( user_dataB != NULL )
  {
    Game::Entity * entity = Game::Entities::UserData::to_entity(user_dataB);
    entity->begin_collision(contact);
  }
}

void CollisionDispatcher::EndContact(b2Contact * contact)
{
  if( contact == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }

  b2Fixture * fixtureA = contact->GetFixtureA();
  b2Fixture * fixtureB = contact->GetFixtureB();
  
  void * user_dataA = fixtureA->GetUserData();
  void * user_dataB = fixtureB->GetUserData();
  
  if( user_dataA != NULL )
  {
    Game::Entity * entity = Game::Entities::UserData::to_entity(user_dataA);
    entity->end_collision(contact);
  }
  
  if( user_dataB != NULL )
  {
    Game::Entity * entity = Game::Entities::UserData::to_entity(user_dataB);
    entity->end_collision(contact);
  }
}

void CollisionDispatcher::PreSolve(
  b2Contact * contact, 
  const b2Manifold * old_manifold
)
{
  if( contact == NULL || old_manifold == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }

  b2Fixture * fixtureA = contact->GetFixtureA();
  b2Fixture * fixtureB = contact->GetFixtureB();
  
  void * user_dataA = fixtureA->GetUserData();
  void * user_dataB = fixtureB->GetUserData();
  
  if( user_dataA != NULL )
  {
    Game::Entity * entity = Game::Entities::UserData::to_entity(user_dataA);
    entity->pre_solve_collision(contact, old_manifold);
  }
  
  if( user_dataB != NULL )
  {
    Game::Entity * entity = Game::Entities::UserData::to_entity(user_dataB);
    entity->pre_solve_collision(contact, old_manifold);
  }
}

//void CollisionDispatcher::PostSolve(
//  b2Contact* contact, 
//  const b2ContactImpulse* impulse
//)
//{
//  if( contact == NULL || impulse == NULL )
//  {
//    BOOST_THROW_EXCEPTION(Game::Exception());
//  }

//  b2Fixture * fixtureA = contact->GetFixtureA();
//  b2Fixture * fixtureB = contact->GetFixtureB();
  
//  void * user_dataA = fixtureA->GetUserData();
//  void * user_dataB = fixtureB->GetUserData();
  
//  if( user_dataA != NULL )
//  {
//    Game::Entity * entity = Game::Entities::UserData::to_entity(user_dataA);
//    entity->post_solve_collision(contact, impulse);
//  }
  
//  if( user_dataB != NULL )
//  {
//    Game::Entity * entity = Game::Entities::UserData::to_entity(user_dataB);
//    entity->post_solve_collision(contact, impulse);
//  }
//}



}


