#include "Game/Controller.h"

namespace Game
{
  Controller::Controller(boost::shared_ptr<Game::Config> conf)
    : config(conf),
      window(conf),
      world(conf)
  {
  }
  
  Controller::~Controller()
  {
  }
  
  void Controller::start()
  {
    sf::Event sfmlEvent;
    
    while( this->window.isOpen() )
    {
      while( this->window.pollEvent(sfmlEvent) )
      {
        this->handle_event(sfmlEvent);
      }
        
      this->step();
      this->render();
      system("sleep 0.01");
    }
  }
  
  void Controller::step()
  {
    this->world.step_default();
    this->world.b2world()->ClearForces();
  }
  
  void Controller::render()
  {
    this->window.clear();
    this->world.render(this->window);
    this->window.display();
  }
  
  void Controller::handle_event(const sf::Event& sfml_event)
  {
    if( sfml_event.type == sf::Event::KeyPressed )
    {
      this->handle_input(sfml_event);
    }
    else if( sfml_event.type == sf::Event::Closed )
    {
      this->window.close();
    }
  }
  
  void Controller::handle_input(const sf::Event& input)
  {
    this->world.handle_input(input);
  }
}
