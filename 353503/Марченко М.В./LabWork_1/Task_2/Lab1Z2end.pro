#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T20:24:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PaintFigure
TEMPLATE = app


SOURCES += main.cpp\
    Figures/arrow.cpp \
    Figures/circle.cpp \
    Figures/hexagon.cpp \
    Figures/rectangle.cpp \
    Figures/romb.cpp \
    Scenes/paintscene.cpp \
    Figures/figure.cpp \
    Figures/star5.cpp \
    Figures/star6.cpp \
    Figures/star8.cpp \
    Figures/triangle.cpp \
    Figures/square.cpp \
    Windows/mainwindow.cpp


HEADERS  += Windows/mainwindow.h \
    Figures/arrow.h \
    Figures/circle.h \
    Figures/hexagon.h \
    Figures/rectangle.h \
    Figures/romb.h \
    Scenes/paintscene.h \
    Figures/figure.h \
    Figures/star5.h \
    Figures/star6.h \
    Figures/star8.h \
    Figures/triangle.h \
    Figures/square.h

FORMS    += Windows/mainwindow.ui
