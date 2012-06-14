#ifndef GAMEUTILUTIL_H
#define GAMEUTILUTIL_H

#include <iostream>

#include "Game/Exception.h"
#include "Game/Entities/Id.h"

namespace Game
{
  namespace Util
  {
    /**
     * @brief A large enough pie
     */
    static const float pi = 3.14f;
    
    /**
     * @brief Scale between Box2d (meters) and SFML (pixels)
     */
    static const float pixel_per_meter = 128.0f;
  
    /**
     * @brief Convert pixels to meters
     * @param pixels
     * @return meters
     */
    float pixel_to_meter(const float pixels);
    
    /**
     * @brief Converts meters to pixels
     * @param meters
     * @return pixels
     */
    float meter_to_pixel(const float meters);
    
    /**
     * @brief Convert radians to degrees
     * @param rad radians
     * @return degrees
     */
    float rad_to_deg(const float rad);
  }
}

#endif // GAMEUTILUTIL_H
