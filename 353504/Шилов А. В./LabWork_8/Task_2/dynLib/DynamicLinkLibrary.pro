QT -= gui

TEMPLATE = lib
CONFIG += dll
CONFIG += c++17

DEFINES += DYNAMICLINKLIBRARY_LIBRARY

SOURCES += \
    dynamiclinklibrary.cpp

HEADERS += \
    DynamicLinkLibrary_global.h \
    dynamiclinklibrary.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
