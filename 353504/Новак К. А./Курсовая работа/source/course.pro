
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 5): QT += widgets
TARGET = course
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
SOURCES += \
        main.cpp \
    widget.cpp

HEADERS += \
    widget.h \
    graphs.h

FORMS += \
    widget.ui
