#include "Game/Entities/Type.h"

namespace Game
{
  namespace Entities
  {
    namespace Type
    {
      void * to_user_data(Game::Entities::Type::t_entities_type entity_type)
      {
        return reinterpret_cast<void *>(entity_type);
      }
      
      Game::Entities::Type::t_entities_type to_entity_type(void * user_data)
      {
        if( user_data == NULL )
        {
          BOOST_THROW_EXCEPTION(Game::Exception());
        }
        
        using namespace Game::Entities::Type;
        
        return static_cast<t_entities_type>(
          reinterpret_cast<unsigned int>(
            user_data
          )
        );
      }
    }
  }
}

