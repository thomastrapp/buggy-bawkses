#ifndef GAMEENTITIESID_H
#define GAMEENTITIESID_H

#include <cstddef>

#include "Game/Exception.h"

namespace Game
{
  namespace Entities
  {
    /**
     * @brief Entity Ids.
     */
    namespace Id 
    {
      /**
       * @brief The t_entities_id enum defines constants for Entity Ids.
       */
      enum t_entities_id {
        //INVALID     = 1 << 0, 
        PLAYER      = 1 << 1, 
        FOOT_SENSOR = 1 << 2,
        WALL        = 1 << 3,
        BARTENDER   = 1 << 4,
        BAR         = 1 << 5
      };
    }
  }
}

#endif // GAMEENTITIESID_H
