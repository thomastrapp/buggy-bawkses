#include <iostream>
#include <cstdlib>

#include <boost/exception/diagnostic_information.hpp>

#include "Game/Controller.h"
#include "Game/Config.h"
#include "Game/Exception.h"

#pragma message "X-Panic-Mode: SNAFU"

/**
 * Code smells & todos:
 * * CollisionDispatcher violates DRY
 * * Implement Player::jump (maybe gradually increase to top speed?)
 * * change configuration option window-width/-height from int to unsigned int 
 * (new template specialisation etc)
 */

int main(int argc, char ** argv)
{
  try
  {
    boost::shared_ptr<Game::Config> config(new Game::Config);
    config->parse_command_line(argc, argv);
    
    // if --help is supplied on cmdline
    if( config->is_set("help") )
    {
      config->print_description(std::cout);
      return EXIT_SUCCESS;
    }
  
    Game::Controller controller(config);
    // start game loop
    controller.start();
  }
  catch( Game::Exception const& e )
  {
    std::cerr << "\n########\n"
              << "Error: Caught Game::Exception (Toplevel): \n" 
              << boost::diagnostic_information(e) 
              << "########\n"
              << std::endl;

    return EXIT_FAILURE;
  }
  #ifdef DEBUG
  catch( boost::exception const& e )
  {
    std::cerr << "\n########\n"
              << "Error: Caught boost::exception (Toplevel): \n" 
              << boost::diagnostic_information(e) 
              << "########\n"
              << std::endl;

    return EXIT_FAILURE;
  }
  catch( std::exception const& e)
  {
    std::cerr << "\n########\n"
              << "Error: Caught std::exception (Toplevel): \n" 
              << boost::diagnostic_information(e) 
              << "########\n"
              << std::endl;

    return EXIT_FAILURE;
  }
  #endif
  
  #ifdef DEBUG
    std::cout << "EOF" << std::endl;
  #endif
  return EXIT_SUCCESS;
}
