#ifndef GAMEENTITIESID_H
#define GAMEENTITIESID_H

#include <cstddef>

#include "Game/Exception.h"

namespace Game
{
  namespace Entities
  {
    /**
     * @brief Constants and functions related to Entity Ids.
     */
    namespace Id 
    {
      /**
       * @brief The t_entities_id enum defines constants for Entity Ids.
       *
       * These constants may then be used to identify participants in 
       * collisions.
       */
      enum t_entities_id {
        /*
        INVALID     = 1, 
        */
        PLAYER      = 2, 
        PLAYER_FOOT = 4,
        STAGE       = 8,
        WALL_LEFT   = 16,
        WALL_BOTTOM = 32,
        WALL_RIGHT  = 64
      };
      
      /**
       * @brief Convert a t_entities_id value to b2Fixture user data.
       *
       * Helper function to convert between int and void pointer.
       * Returned pointer must not be referenced.
       *
       * @param entity_id A constant from enum t_entities_id
       * @return An (invalid) void pointer, whose address equals passed
       * parameter entity_id
       */
      void * to_user_data(Game::Entities::Id::t_entities_id entity_id);
      
      /**
       * @brief Convert b2Fixture user data to a t_entities_id value
       *
       * Helper function to convert between void pointer and int.
       * Throws Game::Exception if user_data is NULL.
       *
       * @param user_data
       * @return A constant from enum t_entities_id, whose value equals the
       * address of passed parameter user_data
       * @throws Game::Exception
       */
      Game::Entities::Id::t_entities_id to_entity_id(void* user_data);
    }
  }
}

#endif // GAMEENTITIESID_H
