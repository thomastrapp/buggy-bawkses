#include "Game/CollisionDispatcher.h"

// solve circular dependencies
#include "Game/Entity.h"

namespace Game
{

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


}


