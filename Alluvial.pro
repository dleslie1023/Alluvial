TEMPLATE = app

QT += qml quick widgets core

QT -= gui

TARGET = HttpGetExample
CONFIG   += console c++11
CONFIG   -= app_bundle
QT += network
TEMPLATE = app

SOURCES += main.cpp \
    schandler.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    schandler.h
