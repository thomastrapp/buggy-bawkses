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
       */
      enum t_entities_id {
        /*
        INVALID     = 1 << 0, 
        */
        PLAYER      = 1 << 1, 
        PLAYER_FOOT = 1 << 2,
        WALL        = 1 << 3,
        BAR         = 1 << 4
      };
    }
  }
}

#endif // GAMEENTITIESID_H
