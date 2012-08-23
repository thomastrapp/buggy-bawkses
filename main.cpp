/*
  This file is part of the "Buggy Bawkses" Project.

  Copyright (C) 2012 Thomas Trapp; mailto: bawkses@thomastrapp.com

  "Buggy Bawkses" is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, 
  Boston, MA  02110-1301, USA.

  See COPYING for details.
*/

#include <cstdlib>
#include <iostream>

#include <boost/exception/diagnostic_information.hpp>

#include "Game/Controller.h"
#include "Game/Config.h"
#include "Game/Exception.h"

#pragma message "X-Panic-Mode: SNAFU"

/**
 * \mainpage
 *
 * See readme.txt
 */


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
  
  return EXIT_SUCCESS;
}
