#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game/Config.h"

namespace Game
{
/**
 * @brief A wrapper for sf::RenderWindow
 */
class Window : public sf::RenderWindow
{
public:
  /**
   * @brief Construct a Window
   *
   * Respects configuration options: window-width and window-height.
   * Sets up a sf::View.
   *
   * @param conf A shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as internal key/value pairs.
   */
  Window(boost::shared_ptr<Game::Config> conf);
  ~Window() {}
  
  /**
   * @brief Move the view by given offset
   * @param offset_y Amount of pixels to move y-axis
   */
  void move_view_y(const float offset_y);

private:
  Window(Game::Window const&);
  Window& operator=(Game::Window const&);
  
  /**
   * @brief A shared_ptr to Game::Config, a class that stores user supplied
   * configuration, as well as internal key/value pairs.
   */
  boost::shared_ptr<Game::Config> config;
};
}

#endif // GAMEWINDOW_H
