QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    фигуры/circle.cpp \
    фигуры/figures.cpp \
    фигуры/hexagon.cpp \
    фигуры/polyline.cpp \
    фигуры/rhombus.cpp \
    фигуры/square.cpp \
    фигуры/triangle.cpp \
    фигуры/Звёзды/star5.cpp \
    фигуры/Звёзды/star6.cpp \
    фигуры/Звёзды/star7.cpp \
    фигуры/Звёзды/star8.cpp \
    фигуры/Звёзды/stars.cpp

HEADERS += \
    mainwindow.h \
    фигуры/circle.h \
    фигуры/figures.h \
    фигуры/hexagon.h \
    фигуры/polyline.h \
    фигуры/rhombus.h \
    фигуры/square.h \
    фигуры/triangle.h \
    фигуры/Звёзды/star5.h \
    фигуры/Звёзды/star6.h \
    фигуры/Звёзды/star7.h \
    фигуры/Звёзды/star8.h \
    фигуры/Звёзды/stars.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
