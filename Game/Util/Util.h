#ifndef UTIL_H
#define UTIL_H

#include <iostream>

#include "Game/Exception.h"

namespace Game
{
  namespace Util
  {
    static const float pi = 3.14f;
    static const float pixel_per_meter = 128.0f;
  
    float pixel_to_meter(const float pixels);
    float meter_to_pixel(const float meters);
    
    float rad_to_deg(const float rad);
  }
}

#endif // UTIL_H
