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

#include "Game/Registry.h"

namespace Game
{
  Registry::Registry()
  : reg()
  {
    this->_fill_registry();
  }
  
  template<class T>
  T Registry::get(const std::string &key) const
  {
    t_reg_map::const_iterator it = this->reg.find(key);
    
    if( it == this->reg.end() )
    {
      BOOST_THROW_EXCEPTION(Game::Exception());
    }
    else
    {
      return boost::get<T>(it->second);
    }
  }
  
  // Template specifications
  // This allows us to keep the definition of Registry::get<T>(..) in 
  // the .cpp file
  template bool Registry::get<bool>(const std::string& key) const;
  template int Registry::get<int>(const std::string& key) const;
  template float Registry::get<float>(const std::string& key) const;
  template std::string Registry::get<std::string>(const std::string& key) const;
  
  template<class T>
  void Registry::set(const std::string &key, T value)
  {
    this->reg[key] = t_reg_value(value);
  }
  
  // Template specifications
  // This allows us to keep the definition of Registry::set<T>(..) in 
  // the .cpp file
  template void Registry::set<bool>(const std::string &key, bool value);
  template void Registry::set<int>(const std::string &key, int value);
  template void Registry::set<float>(const std::string &key, float value);
  template void Registry::set<std::string>(
    const std::string &key, 
    std::string value
  );
  
  bool Registry::exists(const std::string &key) const
  {
    t_reg_map::const_iterator it = this->reg.find(key);
    return it != this->reg.end();
  }
  
  void Registry::_fill_registry()
  {
    // The explicit conversion from 'const char *' to std::string here is 
    // important.
    // A t_reg_value may contain one of the following types: 
    // bool, int, std::string, float
    // C++ implicit conversion magic prefers to convert 'const char *' to bool
    // over conversion from 'const char *' to std::string, because:
    //
    // 1. Pointers can be implicitly converted to bool
    // 2. A conversion from 'const char *' to std::string involves constructing
    //    std::string: std::basic_string(const CharT* s)
    // 3. Conversion magic prefers conversions that are less work, which 
    //    favors conversion from char * to bool over constructing a 
    //    std::string.
    //
    // See 'C++ Templates' by Vandevoorde, Appendix B.2 
    //
    // So we explicitly convert 'const char *' to std::string and stay on the
    // sunny side of life.
    this->reg.insert(
      std::pair<std::string, t_reg_value>(
        "window-title", 
        std::string("Buggy Bawkses!")
      )
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("player-height", 30.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("player-width", 10.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("player-density", 1.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("player-friction", 1.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("player-top-speed", 30.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("stage-walls-width", 20.0f)
    );
    // Multiple of window-height
    this->reg.insert(
      std::pair<std::string, t_reg_value>("wall-height-scale", 4.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("bar-height", 20.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("bar-spacing", 100.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("bar-pre-fill", 400.0f)
    );
    // Multiple of window-with
    this->reg.insert(
      std::pair<std::string, t_reg_value>("bar-min-width", 0.1f)
    );
    // Multiple of window-with
    this->reg.insert(
      std::pair<std::string, t_reg_value>("bar-max-width", 0.6f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("new-level-offset", 1000)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("gravity-x", 0.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("gravity-y", 9.8f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("timestep", 1.0f/60.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("velocity-iterations", 8)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("position-iterations", 3)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("allow-sleeping", true)
    );
  }
}
