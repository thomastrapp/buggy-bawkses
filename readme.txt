Buggy Bawkses!
-------------------

Dependencies:
  - SFML 2.0 RC1, http://www.sfml-dev.org/
  - Box2D 2.2.1, http://code.google.com/p/box2d/
  - optionally Qtcreator, http://qt.nokia.com/products/developer-tools
    I used version 2.5.0, but older/newer version should work just fine.
  - qmake (>= 4.6.2)
  - boost (>= 1.40)

Build:
  0. In project folder
  1. Run qmake
  2. Run make
  3. There should be a binary named "buggy_bawkses"
  4. Done!

Generate documentation:
  0. In project folder, run:
     doxygen ./Doxyfile
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


Tips for debian/ubuntu users:
------------------------------

  Building Box2D from source:
  ----------------------------
    0. Run as root: 
       apt-get build-dep libbox2d0 # apt-get may install unmet dependencies 
                                   # for Box2D
    1. Download Box2D 2.2.1 and unpack
    2. In unpacked folder run:
       cmake .  # Don't forget the dot; cmake configures the build 
       make     # Box2D will now be built
    3. Run as root:
       make install  # This will install the Box2D header files as well as the
                     # shared libraries
    4. Done!


  Building SFML from source:
  ---------------------------
  (It may be sufficient to install the precompiled libraries for your 
   architecture: 
   "SFML 2.0 Release Candidate - C++ | version 2.0 RC | 32/64bit"
   This includes needed header files)
   
    0. Run as root: 
       apt-get build-dep libsfml # apt-get may install unmet dependencies for 
                                 # SFML
    1. Download https://github.com/LaurentGomila/SFML/tarball/master and unpack
    2. In unpacked folder run:
       cmake .  # Don't forget the dot; cmake configures the build 
       make     # SFML will now be built
    3. Run as root:
       make install  # This will install the SFML header files as well as the
                     # shared libraries
    4. Done!
  
  
  Installing qmake, boost and qtcreator:
  ---------------------------------------
    0. Hints: 
         - Package names may vary between distros and versions.
         - The packages in your distro's repository might be outdated.
    1. Run as root:
       apt-get install qt4-qmake libboost-dev qtcreator
       

  Check if all libraries can be found by the linker:
  ------------------------------------------------------
    0. This shell command echoes "All OK" if all libraries were found:
       ld -lsfml-graphics -lsfml-window -lsfml-system \
       -lboost_program_options -lBox2D -o /tmp/buggy_bawkses_linker_test \
       && echo "All OK"
    1. ld tries to link these libraries, creating the executable 
       /tmp/buggy_bawkses_linker_test. If it cannot load a library it prints
       the library's name and exits indicating failure. If all went well it 
       will still print an error message stating that it couldn't find an entry
       point (=main). This error can safely be ignored. 

