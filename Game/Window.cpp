#include "Game/Window.h"

namespace Game
{

Window::Window(boost::shared_ptr<Game::Config> conf)
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
      -1.0f * static_cast<float>(conf->get<int>("window-height")),
      static_cast<float>(conf->get<int>("window-width")), 
      static_cast<float>(conf->get<int>("window-height"))
    )
  );
  this->setView(view); 
  this->setVerticalSyncEnabled(true);
  this->setKeyRepeatEnabled(false);
}

void Window::move_view_y(const float offset_y)
{
  sf::View view = this->getView();
  view.move(0.0f, offset_y);
  this->setView(view);
}

}
