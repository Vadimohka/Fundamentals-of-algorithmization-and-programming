QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConnectedFour
TEMPLATE = app

CONFIG += c++14

RESOURCES += data/icons.qrc

DISTFILES += \
    src/src.pri

include(src/src.pri)
