QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    figurecircle.cpp \
    figurehexagon.cpp \
    figurepolyline.cpp \
    figurerhombus.cpp \
    figures.cpp \
    figuresquare.cpp \
    figuretriangle.cpp \
    main.cpp \
    mainwindow.cpp \
    star.cpp \
    star_5.cpp \
    star_6.cpp \
    star_7.cpp \
    star_8.cpp

HEADERS += \
    figurecircle.h \
    figurehexagon.h \
    figurepolyline.h \
    figurerhombus.h \
    figures.h \
    figuresquare.h \
    figuretriangle.h \
    mainwindow.h \
    star.h \
    star_5.h \
    star_6.h \
    star_7.h \
    star_8.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
