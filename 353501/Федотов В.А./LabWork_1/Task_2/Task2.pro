QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customScene.cpp \
    main.cpp \
    mainwindow.cpp \
    shape.cpp \
    shapeCircle.cpp \
    shapePolyline.cpp \
    shapeRectangle.cpp \
    shapeRhombus.cpp \
    shapeRightPolygon.cpp \
    shapeSquare.cpp \
    shapeStar.cpp \
    shapeTriangle.cpp

HEADERS += \
    customScene.h \
    mainwindow.h \
    shape.h \
    shapeCircle.h \
    shapePolyline.h \
    shapeRectangle.h \
    shapeRhombus.h \
    shapeRightPolygon.h \
    shapeSquare.h \
    shapeStar.h \
    shapeTriangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
