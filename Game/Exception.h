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
