#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <boost/exception.hpp>

namespace Game 
{
  /**
   * @brief Game internal Exception
   *
   * Additional information (e.g. file and line where exception was thrown)
   * can be extracted with boost::diagnostic_information()
   */
  class Exception : public virtual std::exception, 
                    public virtual boost::exception
  {
  public:
    explicit Exception()
    {}
  };
}

#endif // GAMEEXCEPTION_H
