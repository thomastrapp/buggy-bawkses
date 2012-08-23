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

#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <string>
#include <ostream>
#include <boost/program_options.hpp>

#include "Game/Registry.h"

namespace Game
{
  
  /**
   * @brief Configuration options
   *
   * Config allows retrieval of user supplied (vm) and internal key/value pairs
   * (Registry).
   */
  class Config
  {
  public:
    Config();
    ~Config() {}
    
    /**
     * @brief Parse user supplied command line options
     *
     * @param argc Amount of elements in argv
     * @param argv All commandline options including command-name
     */
    void parse_command_line(int argc, char ** argv);
    
    /**
     * @brief Output the description of user suppliable options
     *
     * e.g. print all options if @code--help@endcode on cmdline
     *
     * @param os The stream to write to
     */
    void print_description(std::ostream& os) const;
    
    /**
     * @brief Get a value for a key (template method)
     *
     * If the given key exists in the Registry, its value will be returned.
     * Else the value will be retrieved from the variables_map (Config::vm).
     * If the key doesn't exist at all an exception will be thrown.
     *
     * T must be bool, int, float or std::string.
     * 
     * @param key
     * @return value of type bool, int, float or std::string
     */
    template <class T> T get(const std::string& key) const;
    
    /**
     * @brief Check whether an option was supplied by the user
     *
     * This is helpful e.g. to check if the --help parameter is set.
     *
     * @param key 
     * @return bool true if key is in variable map (Config::vm)
     */
    bool is_set(const std::string& key) const;
  
  private:
    Config(Game::Config const&);
    Config& operator=(Game::Config const&);
    
    /**
     * @brief Setup user suppliable options
     *
     * This function defines all user suppliable parameters with descriptions
     * and default values.
     */
    void _fill_option_description();
  
    /**
     * @brief Contains the definition of user suppliable 
     * options
     */
    boost::program_options::options_description desc;
    
    /**
     * @brief Contains key/value pairs that can be changed by the user
     */
    boost::program_options::variables_map vm;
    
    /**
     * @brief A map of internal key/value pairs (cannot be changed by user)
     */
    Game::Registry registry;
  };
}

#endif // GAMECONFIG_H
