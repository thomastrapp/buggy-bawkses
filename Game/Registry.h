#ifndef GAMEREGISTRY_H
#define GAMEREGISTRY_H

#include <map>
#include <utility>
#include <string>
#include <boost/variant.hpp>

#include "Game/Exception.h"

namespace Game
{
  /**
   * @brief The type that defines what can be saved in the Registry. 
   *
   * Value must be one of bool, int, std::string or float
   */
  typedef boost::variant<bool, int, std::string, float> t_reg_value;
  
  /**
   * @brief The map where the key/value pairs are stored
   */
  typedef std::map<std::string, t_reg_value> t_reg_map;
  
  /**
   * @brief Contains internal key/value pairs like Player gravity
   */
  class Registry 
  {
  public:
    Registry();
    ~Registry() {}
    
    /**
     * @brief Get a value for a key (template method)
     * 
     * If a key does not exist a Game::Exception is thrown.
     * T must be one of bool, int, std::string or float.
     *
     * @param key
     * @return value
     * @throws Game::Exception
     */
    template<class T> T get(const std::string &key) const;
    
    /**
     * @brief Set a value for a key (template method)
     *
     * T must be one of bool, int, std::string or float.
     *
     * @param key
     * @param value T must be one of int, std::string or float
     */
    template<class T> void set(const std::string &key, T value);
    
    /**
     * @brief Check if a key exists
     *
     * @param key
     * @return bool true if key exists
     */
    bool exists(const std::string& key) const;
   
  private:
    Registry(Game::Registry const&);
    Registry& operator=(Game::Registry const&);
    
    /**
     * @brief Setup internal values
     */
    void _fill_registry();
    
    /**
     * @brief Contains the key/value pairs
     */
    t_reg_map reg;
  };
}

#endif // GAMEREGISTRY_H
