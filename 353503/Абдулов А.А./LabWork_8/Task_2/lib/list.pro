QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = listheap
TEMPLATE = lib

SOURCES += listheap.cpp
HEADERS +=     listheap.h \
    listnode.h \
