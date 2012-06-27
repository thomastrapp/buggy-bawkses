CONFIG -= qt

CONFIG(debug, debug|release) {
    TARGET = buggy_bawkses_debug
    DEFINES += ENABLE_DEBUG_DRAW \
        DEBUG
}

CONFIG(release, debug|release) { 
    TARGET = buggy_bawkses
}

heap_checker { 
    TARGET = buggy_bawkses_heap_checker
    DEFINES += ENABLE_HEAP_CHECKER
    LIBS += -ltcmalloc
}

SOURCES += main.cpp \
    Game/Config.cpp \
    Game/Registry.cpp \
    Game/World.cpp \
    Game/Controller.cpp \
    Game/Util/Util.cpp \
    Game/Entities/Player.cpp \
    Game/Entity.cpp \
    Game/Util/DebugDraw.cpp \
    Game/Entities/WallLeft.cpp \
    Game/Entities/WallRight.cpp \
    Game/Entities/Wall.cpp \
    Game/CollisionDispatcher.cpp \
    Game/Entities/UserData.cpp \
    Game/Entities/Bar.cpp \
    Game/Window.cpp \
    Game/Entities/FootSensor.cpp \
    Game/Entities/Bartender.cpp
LIBS += -lsfml-graphics \
    -lsfml-window \
    -lsfml-system \
    -lboost_program_options \
    -lBox2D
HEADERS += Game/Window.h \
    Game/Exception.h \
    Game/World.h \
    Game/Config.h \
    Game/Registry.h \
    Game/Controller.h \
    Game/Util/Util.h \
    Game/Entities/Player.h \
    Game/Entity.h \
    Game/Util/DebugDraw.h \
    Game/Entities/Id.h \
    Game/Entities/WallLeft.h \
    Game/Entities/Wall.h \
    Game/Entities/WallRight.h \
    Game/CollisionDispatcher.h \
    Game/Entities/UserData.h \
    Game/Entities/Bar.h \
    Game/Entities/RectangleDef.h \
    Game/Entities/FootSensor.h \
    Game/Entities/Bartender.h
QMAKE_CXXFLAGS_WARN_ON += -Wconversion \
    -Wsign-conversion \
    -Wextra \
    -Werror \
    -pedantic \
    -Wall \
    -Wextra \
    -Wcast-align \
    -Wcast-qual \
    -Wctor-dtor-privacy \
    -Wdisabled-optimization \
    -Wformat=2 \
    -Winit-self \
    -Wlogical-op \
    -Wmissing-declarations \
    -Wmissing-include-dirs \
    -Woverloaded-virtual \
    -Wredundant-decls \
    -Wshadow \
    -Wsign-promo \
    -Wstrict-null-sentinel \
    -Wstrict-overflow=5 \
    -Wswitch-default \
    -Wundef \
    -Wno-unused \
    -Weffc++

OTHER_FILES += \
    readme.txt \
    Doxyfile \
    Testing/run_cppcheck.sh \
    Testing/run_heapcheck.sh \
    Testing/cpplint.py \
    Testing/run_cpplint.sh
