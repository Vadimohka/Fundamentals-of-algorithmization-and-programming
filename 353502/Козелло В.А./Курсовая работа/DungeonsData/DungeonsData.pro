QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    armor.cpp \
    combat.cpp \
    creationform.cpp \
    dice.cpp \
    entity.cpp \
    item.cpp \
    lvlupform.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    player.cpp \
    potion.cpp \
    trinket.cpp \
    weapon.cpp \
    world.cpp

HEADERS += \
    armor.h \
    combat.h \
    constants.h \
    creationform.h \
    dice.h \
    entity.h \
    item.h \
    lvlupform.h \
    mainwindow.h \
    menu.h \
    player.h \
    potion.h \
    trinket.h \
    weapon.h \
    world.h

FORMS += \
    creationform.ui \
    lvlupform.ui \
    mainwindow.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
