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

SOURCES += $$PWD/src/Main.cpp \
    $$PWD/src/Lsystems.cpp \
    $$PWD/src/Turtle.cpp \
    $$PWD/src/Scene.cpp


HEADERS += \
    $$PWD/include/Lsystems.h \
    $$PWD/include/Turtle.h \
    $$PWD/include/Scene.h

DISTFILES += \
    $$PWD/docs/Alphabet1.txt \
    $$PWD/docs/Rule2.txt \
    $$PWD/docs/Rule1.txt \
    $$PWD/docs/Axiom1.txt \
    $$PWD/docs/AlphabetRule1.txt \
    $$PWD/docs/Axiom2.txt \
    $$PWD/docs/Alphabet2.txt \
    $$PWD/docs/AlphabetRule2.txt \

INCLUDEPATH+=$$PWD/include




