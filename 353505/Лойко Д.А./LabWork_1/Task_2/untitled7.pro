QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    figureCircle.cpp \
    figureHexagon.cpp \
    figurePolyline.cpp \
    figureRhombus.cpp \
    figureSquare.cpp \
    figureTriangle.cpp \
    figures.cpp \
    main.cpp \
    mainWindow.cpp \
    star.cpp \
    star_5.cpp \
    star_6.cpp \
    star_7.cpp \
    star_8.cpp

HEADERS += \
    figureCircle.h \
    figureHexagon.h \
    figurePolyline.h \
    figureRhombus.h \
    figureSquare.h \
    figureTriangle.h \
    figures.h \
    mainWindow.h \
    star.h \
    star_5.h \
    star_6.h \
    star_7.h \
    star_8.h

FORMS += \
    mainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
