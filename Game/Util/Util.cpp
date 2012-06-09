#include "Game/Util/Util.h"

namespace Game
{
  namespace Util
  {
    float pixel_to_meter(const float pixels)
    {
      return pixels / Game::Util::pixel_per_meter;
    }
    
    float meter_to_pixel(const float meters)
    {
      return meters * Game::Util::pixel_per_meter;
    }
    
    float rad_to_deg(const float rad)
    {
      return rad * 180 / Game::Util::pi;
    }
  }
}
