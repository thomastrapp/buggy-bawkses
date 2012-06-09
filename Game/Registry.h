#ifndef GAMEREGISTRY_H
#define GAMEREGISTRY_H

#include <cstring>
#include <map>
#include <boost/variant.hpp>

#include "Game/Exception.h"

namespace Game
{
  typedef boost::variant<int, std::string, float> t_reg_value;
  typedef std::map<std::string, t_reg_value> t_reg_map;
  
  class Registry 
  {
  public:
    Registry();
    ~Registry() {}
    
    template<class T>
    T get(const std::string &key) const;
    
    template<class T>
    void set(const std::string &key, T value);
    
    bool exists(const std::string& key) const;
   
  private:
    Registry(Game::Registry const&);
    Registry& operator=(Game::Registry const&);
    
    void _fill_registry();
    
    t_reg_map reg;
  };
}

#endif // GAMEREGISTRY_H
