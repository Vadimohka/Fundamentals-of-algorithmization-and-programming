QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    circle.cpp \
    figures.cpp \
    hexagon.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    rhombus.cpp \
    risovalka.cpp \
    starEight.cpp \
    starFive.cpp \
    starSeven.cpp \
    starSix.cpp \
    stars.cpp \
    triangle.cpp

HEADERS += \
    circle.h \
    figures.h \
    hexagon.h \
    mainwindow.h \
    rectangle.h \
    rhombus.h \
    risovalka.h \
    starEight.h \
    starFive.h \
    starSeven.h \
    starSix.h \
    stars.h \
    triangle.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    T2.pro

FORMS += \
    mainwindow.ui

DISTFILES += \
    T2_3.pro.user
