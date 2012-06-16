#ifndef GAMEENTITIESBAR_H
#define GAMEENTITIESBAR_H

#include <Box2D/Box2D.h>

#include "Game/Entity.h"

namespace Game
{
namespace Entities
{

class Bar : public Entity
{
public:
  Bar(const WallDef& wall_def);
  ~Bar() {}
  
  void render(sf::RenderTarget& renderer);
  void update();
  
  void begin_collision(b2Contact * contact);
  void end_collision(b2Contact * contact);

private:
  Bar(const Bar&);
  Bar& operator=(const Bar&);
};

}
}

#endif // GAMEENTITIESBAR_H
