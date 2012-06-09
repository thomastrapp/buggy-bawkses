#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <boost/exception.hpp>

namespace Game 
{
  class Exception : public virtual std::exception, 
                    public virtual boost::exception
  {
  public:
    explicit Exception()
    {}
  };
}

#endif // GAMEEXCEPTION_H
