#ifndef GAMEENTITIESSTATE_H
#define GAMEENTITIESSTATE_H

namespace Game
{
namespace Entities
{

namespace State
{
  typedef int state_mask;
  
  enum t_entities_state
  {
    NONE        = 0, 
    PLAYER_DEAD = 1 << 1
  };
}

}
}

#endif // GAMEENTITIESSTATE_H
