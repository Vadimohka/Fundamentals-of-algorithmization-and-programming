QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractplayer.cpp \
    botplayer.cpp \
    cards.cpp \
    dealer.cpp \
    deck.cpp \
    gameboard.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    timer.cpp \
    userplayer.cpp

HEADERS += \
    abstractplayer.h \
    botplayer.h \
    cards.h \
    const_numbers.h \
    dealer.h \
    deck.h \
    gameboard.h \
    mainwindow.h \
    menu.h \
    timer.h \
    userplayer.h \
    value.h

FORMS += \
    gameboard.ui \
    mainwindow.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
