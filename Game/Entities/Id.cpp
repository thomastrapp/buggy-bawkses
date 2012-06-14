#include "Game/Entities/Id.h"

namespace Game
{
  namespace Entities
  {
    namespace Id
    {
      void * to_user_data(Game::Entities::Id::t_entities_id entity_id)
      {
        return reinterpret_cast<void *>(entity_id);
      }
      
      Game::Entities::Id::t_entities_id to_entity_id(void * user_data)
      {
        if( user_data == NULL )
        {
          BOOST_THROW_EXCEPTION(Game::Exception());
        }
        
        using namespace Game::Entities::Id;
        
        return static_cast<t_entities_id>(
          reinterpret_cast<unsigned int>(
            user_data
          )
        );
      }
    }
  }
}

