#ifndef GAMEENTITIESWALLRIGHT_H
#define GAMEENTITIESWALLRIGHT_H

#include "Game/Entities/Wall.h"

namespace Game
{
namespace Entities
{

/**
 * @brief Enclosing the game to the right
 */
class WallRight : public Wall
{
public:
  /**
   * @brief Construct a right Wall
   *
   * A concrete implementation of a Wall
   *
   * @param conf A shared_ptr to Game::Config, a class that stores user 
   * supplied configuration, as well as internal key/value pairs.
   * @param game_world A reference to the global World, which is a wrapper for 
   * b2World
   */
  WallRight(boost::shared_ptr<Game::Config> conf, Game::World& game_world);
  ~WallRight() {}
  
private:
  WallRight(const WallRight&);
  WallRight& operator=(const WallRight&);
};

}
}


#endif // GAMEENTITIESWALLRIGHT_H
