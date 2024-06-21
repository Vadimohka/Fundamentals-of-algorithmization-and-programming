QT -= gui

TARGET = QuiLib
TEMPLATE = lib

DEFINES += QUILIB_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES +=

HEADERS += \
    Vector.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}
