TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS+=-std=c99
QMAKE_CFLAGS+=$$system(sdl2-config  --cflags)
message(output from sdl2-config --cflags added to CXXFLAGS= $$QMAKE_CFLAGS)
INCLUDEPATH+=/usr/bin/sdl2-config
INCLUDEPATH+=/usr/share/doc/SDL2_image
LIBS+=$$system(sdl2-config  --libs)
message(output from sdl2-config --libs added to LIB=$$LIBS)
LIBS+=-lSDL2_image -lGL

SOURCES =$$PWD/src/main.cpp \
         $$PWD/src/branch.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS +=$$PWD/include/l-systems.h \
          $$PWD/include/turtle.h \
          $$PWD/include/branch.h

