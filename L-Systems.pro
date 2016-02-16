TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    branch.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    l-systems.h \
    turtle.h \
    branch.h

