#include "Game/CollisionDispatcher.h"

// solve circular dependencies
#include "Game/Entity.h"

namespace Game
{

/*
 * TODO: Respect DRY
 * maybe even use boost::function
 */ 
#pragma message "Clean CollisionDispatcher"

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


