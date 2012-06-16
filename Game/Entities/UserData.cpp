#include "Game/Entities/UserData.h"

// solve circular dependencies
#include "Game/Entity.h"

namespace Game
{
namespace Entities
{
namespace UserData
{

void * to_user_data(Game::Entity * entity)
{
  if( entity == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }

  return static_cast<void *>(entity);
}

Game::Entity * to_entity(void * user_data)
{
  if( user_data == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }
  
  return static_cast<Game::Entity *>(user_data);
}

}
}
}
