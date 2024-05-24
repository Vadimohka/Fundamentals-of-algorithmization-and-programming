QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    figures/bigltypefigure.cpp \
    figures/diagonalstick2figure.cpp \
    figures/inverseltypefigure.cpp \
    figures/inversestypefigure.cpp \
    figures/ltypefigure.cpp \
    figures/miniltypefigure.cpp \
    figures/square2typefigure.cpp \
    figures/stick4typefigure.cpp \
    figures/stypefigure.cpp \
    figures/ttypefigure.cpp \
    figures/typesoffigures.cpp \
    backtrackinggenerator.cpp \
    dialogs/dialogaboutgame.cpp \
    dialogs/dialogaboutloss.cpp \
    dialogs/dialogchoosinggamestart.cpp \
    figureitem.cpp \
    gamefield.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp

HEADERS += \
    figures/bigltypefigure.h \
    figures/diagonalstick2figure.h \
    figures/inverseltypefigure.h \
    figures/inversestypefigure.h \
    figures/ltypefigure.h \
    figures/miniltypefigure.h \
    figures/square2typefigure.h \
    figures/stick4typefigure.h \
    figures/stypefigure.h \
    figures/ttypefigure.h \
    figures/typesoffigures.h \
    backtrackinggenerator.h \
    dialogs/dialogaboutgame.h \
    dialogs/dialogaboutloss.h \
    dialogs/dialogchoosinggamestart.h \
    figureitem.h \
    gamefield.h \
    mainmenu.h \
    mainwindow.h

FORMS += \
    dialogs/dialogaboutgame.ui \
    dialogs/dialogaboutloss.ui \
    dialogs/dialogchoosinggamestart.ui \
    mainmenu.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
