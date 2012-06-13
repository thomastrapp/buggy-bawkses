#include "Game/Controller.h"

namespace Game
{
  Controller::Controller(boost::shared_ptr<Game::Config> conf)
    : config(conf),
      window(conf),
      world(conf)
      #ifdef ENABLE_DEBUG_DRAW
      , debug_draw(this->window)
      #endif
  {
    #ifdef ENABLE_DEBUG_DRAW
      this->world.b2world()->SetDebugDraw(&(this->debug_draw));
    #endif
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
      
      // TODO: Remove this
      if( system("sleep 0.01") > 0 )
      {
        BOOST_THROW_EXCEPTION(Game::Exception());
      }
    }
  }
  
  void Controller::step()
  {
    this->world.step();
  }
  
  void Controller::render()
  {
    this->window.clear();
    this->world.update();
    this->world.render(this->window);
    
    #ifdef ENABLE_DEBUG_DRAW
      this->world.b2world()->DrawDebugData();
    #endif
    
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
