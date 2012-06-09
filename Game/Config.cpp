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
      (
        "gravity-x", 
        boost::program_options::value<float>()->default_value(0.0f), 
        "Gravity sideways"
      )
      (
        "gravity-y", 
        boost::program_options::value<float>()->default_value(9.8f), 
        "Gravity downwards"
      )
      (
        "timestep", 
        boost::program_options::value<float>()->default_value(1.0f/60.0f), 
        "Timestep"
      )
      (
        "velocity-iterations", 
        boost::program_options::value<int>()->default_value(8), 
        "Velocity iterations"
      )
      (
        "position-iterations", 
        boost::program_options::value<int>()->default_value(3), 
        "Position iterations"
      )
        ;
  }
  
  void Config::print_description(std::ostream& os) const
  {
    this->desc.print(os);
  }
}
