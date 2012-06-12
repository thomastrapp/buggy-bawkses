#ifndef GAMEENTITIESID_H
#define GAMEENTITIESID_H

#include <cstddef>

#include "Game/Exception.h"

namespace Game
{
  namespace Entities
  {
    namespace Type 
    {
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
      
      void * to_user_data(Game::Entities::Type::t_entities_type entity_type);
      Game::Entities::Type::t_entities_type to_entity_type(void* user_data);
    }
  }
}

#endif // GAMEENTITIESID_H
