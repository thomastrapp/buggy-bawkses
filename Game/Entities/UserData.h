#ifndef GAMEENTITIESUSERDATA_H
#define GAMEENTITIESUSERDATA_H

#include <boost/exception.hpp>

#include "Game/Exception.h"

namespace Game
{
  class Entity;
  
namespace Entities
{
/**
 * @brief Functions to convert from and to b2Fixture user data.
 */
namespace UserData
{

  /**
   * @brief Convert an Entity pointer to b2Fixture user data.
   *
   * Helper function to convert between Entity and void pointer.
   * Throws Game::Exception if entity is NULL.
   *
   * @param entity A pointer to a Game::Entity
   * @return An void pointer, whose address equals passed
   * parameter entity
   * @throws Game::Exception
   */
  void * to_user_data(Game::Entity * entity);
  
  /**
   * @brief Convert b2Fixture user data to a Entity pointer
   *
   * Helper function to convert between void pointer and Entity pointer.
   * Throws Game::Exception if user_data is NULL.
   *
   * @param user_data
   * @return A pointer to a Game::Entity
   * @throws Game::Exception
   */
  Game::Entity * to_entity(void * user_data);

}
}
}

#endif // GAMEENTITIESUSERDATA_H
