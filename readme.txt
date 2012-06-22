Buggy Bawkses!
-------------------

Dependencies:
  - SFML 2.0 RC1, http://www.sfml-dev.org/
  - Box2D 2.2.1, http://code.google.com/p/box2d/
  - optionally Qtcreator, http://qt.nokia.com/products/developer-tools
  - qmake
  - boost

Build:
  0. In project root
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
    
    
  Installing boost:
  ------------------
    0. To find the packages to install, run:
       apt-cache search libboost
    1. Install libboost, e.g. run as root:
       apt-get install libboost-dev
       The package name may vary between distros and versions; some call it
       libboost-all-dev.


  Check if all libraries can be found by the linker:
  ------------------------------------------------------
    0. This shell command echoes "All OK" if all libraries were found:
       ld -lsfml-graphics -lsfml-window -lsfml-system \ 
       -lboost_program_options -lBox2D && echo "All OK"
  
  
  Installing qmake:
  ------------------
    0. Run as root:
       apt-get install qt4-qmake
       The package name may vary between distros and versions.


  Installing QtCreator:
  ----------------------
    0. Run as root: 
       apt-get install qt-creator
    --- or ---
       Download an installer from Qt to get the newest version
    1. Open buggy_bawkses.pro

