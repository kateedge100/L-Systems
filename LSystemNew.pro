TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS+=-std=c99
QMAKE_CFLAGS+=$$system(sdl2-config  --cflags)
message(output from sdl2-config --cflags added to CXXFLAGS= $$QMAKE_CFLAGS)
LIBS+=$$system(sdl2-config  --libs)
message(output from sdl2-config --libs added to LIB=$$LIBS)
LIBS+=-lSDL2_image -lGL -lGLU
OBJECTS_DIR=$$PWD/obj

INCLUDEPATH+=/usr/bin/sdl2-config
INCLUDEPATH+=/usr/share/doc/SDL2_image


FORMS += $$PWD/files/

SOURCES += $$PWD/src/main.cpp \
    $$PWD/src/branch.cpp \
    $$PWD/src/lsystems.cpp \
    $$PWD/src/turtle.cpp \
    $$PWD/src/scene.cpp


HEADERS += \
    $$PWD/include/branch.h \
    $$PWD/include/lsystems.h \
    $$PWD/include/turtle.h \
    $$PWD/include/scene.h

DISTFILES += \
    $$PWD/files/Axiom1.txt \
    $$PWD/files/Angle1.txt \
    $$PWD/files/Rule1.txt \
    $$PWD/files/Rule2.txt \
    files/Alphabet1.txt \
    Alphabet1.txt \
    Rule2.txt \
    Rule1.txt \
    Axiom1.txt \
    Angle1.txt \
    AlphabetRule1.txt \
    Axiom2.txt \
    Alphabet2.txt \
    AlphabetRule2.txt \
    Angle2.txt

INCLUDEPATH+=$$PWD/include
INCLUDEPATH+=$$PWD/GLFunctionsLib/include
LIBS+= -L $$PWD/GLFunctionsLib/lib -lGLFunctionsLib


