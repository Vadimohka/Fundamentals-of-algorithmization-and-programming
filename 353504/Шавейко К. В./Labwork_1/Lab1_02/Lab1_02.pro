QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle.cpp \
    hexagon.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    parallelohram.cpp \
    polygon.cpp \
    rectangle.cpp \
    rhombus.cpp \
    shape.cpp \
    square.cpp \
    star5.cpp \
    star6.cpp \
    star8.cpp \
    triangle.cpp

HEADERS += \
    circle.h \
    hexagon.h \
    line.h \
    mainwindow.h \
    parallelohram.h \
    polygon.h \
    rectangle.h \
    rhombus.h \
    shape.h \
    square.h \
    star5.h \
    star6.h \
    star8.h \
    triangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
