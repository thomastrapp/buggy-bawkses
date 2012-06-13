#include "Game/Config.h"

namespace Game
{
  Config::Config()
  : desc("Options"),
    vm(),
    registry()
  {
    this->_fill_option_description();
  }
  
  void Config::parse_command_line(int argc, char ** argv)
  {
    boost::program_options::store(
      boost::program_options::parse_command_line(argc, argv, this->desc),
      this->vm
    );
    boost::program_options::notify(this->vm);
  }
  
  template <class T> 
  T Config::get(const std::string& key) const
  {
    if( this->registry.exists(key) )
    {
      return this->registry.get<T>(key);
    }
    else
    {
      return this->vm[key].as<T>();
    }
  }
  
  // Template specifications
  // This allows us to keep the definition of Config::get<T>(..) in 
  // the .cpp file
  template bool Config::get<bool>(const std::string& key) const;
  template int Config::get<int>(const std::string& key) const;
  template float Config::get<float>(const std::string& key) const;
  template std::string Config::get<std::string>(const std::string& key) const;
  
  bool Config::is_set(const std::string& key) const
  {
    return this->vm.count(key) > 0;
  }
  
  void Config::_fill_option_description()
  {
    this->desc.add_options()
      (
        "help", 
        "Show help"
      )
      (
        "window-height", 
        boost::program_options::value<int>()->default_value(600), 
        "Window height"
      )
      (
        "window-width", 
        boost::program_options::value<int>()->default_value(800),
        "Window width"
      )
        ;
  }
  
  void Config::print_description(std::ostream& os) const
  {
    this->desc.print(os);
  }
}
