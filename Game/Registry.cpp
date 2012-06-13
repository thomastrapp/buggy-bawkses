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
    this->reg.insert(
      std::pair<std::string, t_reg_value>("window-title", "Buggy Bawkses!")
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("player-size-x", 10.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("player-size-y", 30.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("player-density", 1.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("player-friction", 1.0f)
    );
    this->reg.insert(
      std::pair<std::string, t_reg_value>("stage-walls-width", 20.0f)
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
  }
}
