#ifndef GAMEENTITIESWALLLEFT_H
#define GAMEENTITIESWALLLEFT_H

#include "Game/Entities/Wall.h"

namespace Game
{
namespace Entities
{

/**
 * @brief Enclosing the game to the left
 */
class WallLeft : public Wall
{
public:
  /**
   * @brief Construct a left Wall
   *
   * A concrete implementation of a Wall
   *
   * @param conf A shared_ptr to Game::Config, a class that stores user 
   * supplied configuration, as well as internal key/value pairs.
   * @param game_world A reference to the global World, which is a wrapper for 
   * b2World
   */
  WallLeft(boost::shared_ptr<Game::Config> conf, Game::World& game_world);
  ~WallLeft() {}
  
private:
  WallLeft(const WallLeft&);
  WallLeft& operator=(const WallLeft&);
};

}
}


#endif // GAMEENTITIESWALLLEFT_H
