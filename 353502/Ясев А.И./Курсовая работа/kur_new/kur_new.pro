QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brickwall.cpp \
    bullet.cpp \
    enemy.cpp \
    levelscene.cpp \
    main.cpp \
    player.cpp \
    powerup.cpp \
    square.cpp \
    steelwall.cpp \
    tank.cpp \
    widget.cpp

HEADERS += \
    brickwall.h \
    bullet.h \
    enemy.h \
    levelscene.h \
    player.h \
    powerup.h \
    square.h \
    steelwall.h \
    tank.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/brick.jpg \
    resources/doubledamage.png \
    resources/enemy.png \
    resources/ghost.png \
    resources/heal.png \
    resources/map0.txt \
    resources/map1.txt \
    resources/map2.txt \
    resources/map3.txt \
    resources/map4.txt \
    resources/player.png \
    resources/steel.jpg \
    resources/styles.qss
