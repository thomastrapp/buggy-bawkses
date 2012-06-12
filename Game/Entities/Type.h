#ifndef GAMEENTITIESID_H
#define GAMEENTITIESID_H

#include <cstddef>

#include "Game/Exception.h"

namespace Game
{
  namespace Entities
  {
    /**
     * @brief Encapsulates all constants and function related to Entity types.
     */
    namespace Type 
    {
      /**
       * @brief The t_entities_type enum defines constants for all Entity
       * types.
       *
       * These constants may then be used to identify participants in 
       * collisions.
       */
      enum t_entities_type {
        /*
        INVALID     = 1, 
        */
        PLAYER      = 2, 
        /*
        BAR         = 4, 
        */
        PLAYER_FOOT = 8
      };
      
      /**
       * @brief Convert t_entities_type value to b2Fixture user data.
       *
       * Helper function to convert between int and void pointer.
       * Returned pointer must not be referenced.
       *
       * @param entity_type a constant from enum t_entities_type
       * @return A (invalid) void pointer, whose address equals passed
       * parameter entity_type
       */
      void * to_user_data(Game::Entities::Type::t_entities_type entity_type);
      
      /**
       * @brief Convert b2Fixture user data to a t_entities_type value
       *
       * Helper function to convert between void pointer and int.
       * Throws Game::Exception if user_data is NULL.
       *
       * @param user_data
       * @return A constant from enum t_entities_type, whose value equals the
       * address of passed parameter user_data
       * @throws Game::Exception
       */
      Game::Entities::Type::t_entities_type to_entity_type(void* user_data);
    }
  }
}

#endif // GAMEENTITIESID_H
