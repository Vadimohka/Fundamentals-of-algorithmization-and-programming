QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle.cpp \
    eightpointedstar.cpp \
    fivepointedstar.cpp \
    hexagon.cpp \
    main.cpp \
    mainwindow.cpp \
    par_polygon.cpp \
    parallelogram.cpp \
    rect.cpp \
    rhombus.cpp \
    sixpointedstar.cpp \
    square.cpp \
    triangle.cpp \
    yourdrawing.cpp

HEADERS += \
    circle.h \
    eightpointedstar.h \
    fivepointedstar.h \
    hexagon.h \
    mainwindow.h \
    par_polygon.h \
    parallelogram.h \
    rect.h \
    rhombus.h \
    sixpointedstar.h \
    square.h \
    triangle.h \
    yourdrawing.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
