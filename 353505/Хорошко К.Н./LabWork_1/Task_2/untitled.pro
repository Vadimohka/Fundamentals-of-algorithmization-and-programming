QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TEMPLATE = app
TARGET = YourApp
QT += widgets

SOURCES += \
    circle.cpp \
    draw.cpp \
    elips.cpp \
    figure.cpp \
    hexagon.cpp \
    main.cpp \
    mainwindow.cpp \
    paintscene.cpp \
    rectangle.cpp \
    romb.cpp \
    square.cpp \
    star_eight.cpp \
    star_five.cpp \
    star_six.cpp \
    triangle.cpp

HEADERS += \
    circle.h \
    draw.h \
    elips.h \
    figure.h \
    hexagon.h \
    mainwindow.h \
    paintscene.h \
    rectangle.h \
    romb.h \
    square.h \
    star_eight.h \
    star_five.h \
    star_six.h \
    triangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
