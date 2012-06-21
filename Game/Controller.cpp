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
  
  void Controller::start()
  {
    sf::Event sfml_event;
    
    while( this->window.isOpen() )
    {
      while( this->window.pollEvent(sfml_event) )
      {
        this->handle_event(sfml_event);
      }
      
      this->step();
      
      // Don't immediately begin to move the camera.
      // Replace this hack with a Game::State.
      // Camera movement should only start if the player reaches the top of 
      // the view.
      static int i = 0;
      if( ++i > 100 )
        this->window.move_view_y(-2.0f);

      this->render();
      
      // Replace throttling with sf::Clock
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
    const sf::View current_view(this->window.getView());
    
    this->window.clear();
    this->world.update(current_view);
    this->world.render(this->window);
    
    #ifdef ENABLE_DEBUG_DRAW
      this->world.b2world()->DrawDebugData();
    #endif
    
    this->window.display();
  }
  
  void Controller::handle_event(const sf::Event& event)
  {
    switch(event.type)
    {
      case sf::Event::Closed:
      {
        this->window.close();
        break;
      }
      case sf::Event::KeyPressed:
      case sf::Event::KeyReleased:
      {
        this->world.handle_input(event);
        break;
      }
      default:
      {
        break;
      }
    }
  }
}
