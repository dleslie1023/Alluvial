TEMPLATE = app

QT += sql
QT += qml quick widgets


SOURCES += main.cpp \
    songhandler.cpp \
    playlisthandler.cpp \
    databasehandler.cpp \
    JSONhandler.cpp \
    queryhandler.cpp

RESOURCES += qml.qrc

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    songhandler.h \
    playlisthandler.h \
    databasehandler.h \
    JSONhandler.h \
    queryhandler.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/release/ -ltag
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/debug/ -ltag
else:unix: LIBS += -L/usr/lib/x86_64-linux-gnu/ -ltag

INCLUDEPATH += /usr/lib/x86_64-linux-gnu
DEPENDPATH += /usr/lib/x86_64-linux-gnu
