CONFIG(debug, debug|release) {
    TARGET = buggy_bawkses_debug
    DEFINES += ENABLE_DEBUG_DRAW \
        DEBUG
}

CONFIG(release, debug|release) { 
    TARGET = buggy_bawkses
}

SOURCES += main.cpp \
    Game/Config.cpp \
    Game/Registry.cpp \
    Game/World.cpp \
    Game/Controller.cpp \
    Game/Util/Util.cpp \
    Game/Entities/Player.cpp \
    Game/Entity.cpp \
    Game/Entities/Stage.cpp \
    Game/Entities/Rectangle.cpp \
    Game/Entities/Type.cpp \
    Game/Util/DebugDraw.cpp
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
    Game/Entities/Stage.h \
    Game/Entities/Rectangle.h \
    Game/Entities/RectangleDef.h \
    Game/Entities/Type.h \
    Game/Util/DebugDraw.h
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
