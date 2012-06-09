#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <cstring>
#include <ostream>
#include <boost/program_options.hpp>

#include "Game/Registry.h"

namespace Game
{
  class Config
  {
  public:
    Config();
    ~Config() {}
    
    void parse_command_line(int argc, char ** argv);
    void print_description(std::ostream& os) const;
    
    template <class T> T get(const std::string& key) const;
    
    bool is_set(const std::string& key) const;
  
  private:
    Config(Game::Config const&);
    Config& operator=(Game::Config const&);
    void _fill_option_description();
  
    boost::program_options::options_description desc;
    boost::program_options::variables_map vm;
    
    Game::Registry registry;
  };
}

#endif // GAMECONFIG_H
