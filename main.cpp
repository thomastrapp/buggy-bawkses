#include <iostream>
#include <cstdlib>

#include <boost/exception/diagnostic_information.hpp>

#include "Game/Controller.h"
#include "Game/Config.h"
#include "Game/Exception.h"

int main(int argc, char ** argv)
{
  try
  {
    boost::shared_ptr<Game::Config> config(new Game::Config);
    config->parse_command_line(argc, argv);
    
    if( config->is_set("help") )
    {
      config->print_description(std::cout);
      return EXIT_SUCCESS;
    }
  
    Game::Controller controller(config);
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
  // Debug
  catch( boost::exception const& e )
  {
    std::cerr << "\n########\n"
              << "Error: Caught boost::exception (Toplevel): \n" 
              << boost::diagnostic_information(e) 
              << "########\n"
              << std::endl;

    return EXIT_FAILURE;
  }
  
  std::cout << "EOF" << std::endl;
  return EXIT_SUCCESS;
}

