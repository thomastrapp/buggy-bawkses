#ifndef GAMECOLLISIONDISPATCHER_H
#define GAMECOLLISIONDISPATCHER_H

#include <boost/exception.hpp>

#include <Box2D/Box2D.h>

#include "Game/Exception.h"
#include "Game/Entities/UserData.h"

namespace Game
{

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
  
  void PreSolve(b2Contact* contact, const b2Manifold* old_manifold);
  void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
  
private:
  CollisionDispatcher(const CollisionDispatcher&);
  CollisionDispatcher& operator=(const CollisionDispatcher&);
};


}

#endif // GAMECOLLISIONDISPATCHER_H
