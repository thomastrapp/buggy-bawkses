#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game/Config.h"

namespace Game
{
  class Window : public sf::RenderWindow
  {
  public:
    Window(boost::shared_ptr<Game::Config> conf)
    : sf::RenderWindow
      (
        sf::VideoMode
        (
          static_cast<unsigned int>(conf->get<int>("window-width")), 
          static_cast<unsigned int>(conf->get<int>("window-height"))
        ),
        conf->get<std::string>("window-title")
      ),
      config(conf)
    {
      sf::View view(
        sf::FloatRect(
          0.0f, 
          0.0f, 
          static_cast<float>(conf->get<int>("window-width")),
          static_cast<float>(conf->get<int>("window-height"))
        )
      );
      this->setView(view);
      this->setVerticalSyncEnabled(true);
    }
  
    ~Window()
    {
    }
  
  private:
    Window(Game::Window const&);
    Window& operator=(Game::Window const&);
    
    boost::shared_ptr<Game::Config> config;
  };
}

#endif // GAMEWINDOW_H
