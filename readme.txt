Buggy Bawkses!
-------------------

Copyright 2012 Thomas Trapp, except where indicated otherwise.
http://www.thomastrapp.com

Bugy Bawkses is free Software under the terms of the GNU General Public License
Version 2. See COPYING for full license text.

Buggy Bawkses is an unfinished clone of the popular game xjump.

Dependencies:
  - SFML 2.0 RC1, http://www.sfml-dev.org/
  - Box2D 2.2.1, http://code.google.com/p/box2d/
  - qmake (>= 4.6.2)
  - boost (>= 1.40)

Optional dependencies:
  - cppcheck (>= 1.5.4), http://cppcheck.sourceforge.net/
    Static code analysis
  - gperftools (>= 2.0), https://code.google.com/p/gperftools/
    Check heap for memory leaks
  - Qtcreator, http://qt.nokia.com/products/developer-tools
    I used version 2.5.0, but older/newer version should work just fine.
    In the subfolder ./Editor there's a "Code style" definition for qtcreator.
    This file can be imported through:
      -> Left panel button "Projects" 
      -> Tab "Code Style Settings"
      -> Button "Import"
      -> Choose the file Editor/qtcreator_code_style.xml

Build:
  0. In project folder
  1. Run qmake
  2. Run make
  3. There should be a binary named "buggy_bawkses"
  4. Done!

Generate documentation:
  0. In project folder, run:
     $ doxygen ./Doxyfile
  1. open Documentation/html/index.html
  2. Done!

Commit rules:
  - Only 80 chars per line (This is enforced by a svn pre-commit hook)
  - No tabs, only spaces (This is enforced by a svn pre-commit hook)
  - Indentation is 2 spaces

3rd party licenses:
  - SFML: zlib license ("Do what the fuck you want"), see
    http://www.sfml-dev.org/license.php and
    http://www.opensource.org/licenses/zlib-license.php
  - Box2D: zlib license ("Do what the fuck you want"), see
    http://code.google.com/p/box2d/source/browse/trunk/Box2D/License.txt
  - Boost: Boost license ("Do what the fuck you want"), see
    http://www.boost.org/users/license.html

Static code analysis with cppcheck:
  0. Make sure you have the cppcheck binary in /usr/bin
  1. Run the wrapper script in project root:
     $ ./Testing/run_cppcheck.sh . # Don't forget the trailing dot

Static code analysis with Google's cpplint.py:
  0. Run the wrapper script in project root:
     $ ./Testing/run_cpplint.sh . # Don't forget the trailing dot
  1. The following lint-checks are disabled:
     - whitespace
         Google seems to be using K&R indent style, we use allman
         
     - legal 
         
     - build/header_guard
         Our header guard is namespace based, while Google's is file based
         
     - build/include_order 
         Boost header files are wrongly convicted as C-header files, thus 
         cpplint is emitting errors
         
     - runtime/references
         Google suggests using pointers wherever a non-const reference is 
         passed. Readability on the caller side is improved, since the caller
         has to explicitly pass a pointer to a mutable object. On the downside
         this introduces the possibility of passing a NULL pointer. So we opt
         for references.
         See http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml
           ?showone=Reference_Arguments#Reference_Arguments
         
     - readability/streams
         Google argues strongly against streams. We don't care here.
         See http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml
           ?showone=Streams#Streams
         

Heap analysis with gperftools:
  0. Compile with target heap_checker
  1. Run 
     $ ./Testing/run_heapcheck.sh ./buggy_bawkses_heap_checker
  2. Memory leaks will be printed, alongside further instructions.
     gperftools indicate leakage of 192 bytes outside of this project (at least
     on my machine). It's probably safe to ignore these two leaks.

Build targets:
  - release
    Binary: buggy_bawkses
  - debug: Your typical debug build. All Box2D shapes are outlined.
    Binary: buggy_bawkses_debug
  - heap_checker: Debug build linked with libtcmalloc (gperftools)
    Binary: buggy_bawkses_heap_checker


Tips for debian/ubuntu users:
------------------------------

  Building Box2D from source:
  ----------------------------
    0. Run as root: 
       $ apt-get build-dep libbox2d0 # apt-get may install unmet dependencies 
                                     # for Box2D
    1. Download Box2D 2.2.1 and unpack
    2. In unpacked folder run:
       $ cmake .  # Don't forget the dot; cmake configures the build 
       $ make     # Box2D will now be built
    3. Run as root:
       $ make install  # This will install the Box2D header files as well as
                       # the shared libraries
    4. Done!


  Building SFML from source:
  ---------------------------
    (It may be sufficient to install the precompiled libraries for your 
     architecture: 
     "SFML 2.0 Release Candidate - C++ | version 2.0 RC | 32/64bit"
     This includes needed header files)
   
    0. Run as root: 
       $ apt-get build-dep libsfml # apt-get may install unmet dependencies for
                                   # SFML
    1. Download https://github.com/LaurentGomila/SFML/tarball/master and unpack
    2. In unpacked folder run:
       $ cmake .  # Don't forget the dot; cmake configures the build 
       $ make     # SFML will now be built
    3. Run as root:
       $ make install  # This will install the SFML header files as well as the
                       # shared libraries
    4. Done!
  
  
  Installing qmake, boost and qtcreator:
  ---------------------------------------
    0. Hints: 
         - Package names may vary between distros and versions.
         - The packages in your distro's repository might be outdated.
    1. Run as root:
       $ apt-get install qt4-qmake libboost-dev qtcreator
       

  Check if all libraries can be found by the linker:
  ---------------------------------------------------
    0. This shell command echoes "All OK" if all libraries were found:
       $ ld -lsfml-graphics -lsfml-window -lsfml-system \
         -lboost_program_options -lBox2D -o /tmp/buggy_bawkses_linker_test \
         && echo "All OK"
    1. ld tries to link these libraries, creating the executable 
       /tmp/buggy_bawkses_linker_test. If it cannot load a library it prints
       the library's name and exits indicating failure. If all went well it 
       will still print an error message stating that it couldn't find an entry
       point (=main). This error can safely be ignored. 

