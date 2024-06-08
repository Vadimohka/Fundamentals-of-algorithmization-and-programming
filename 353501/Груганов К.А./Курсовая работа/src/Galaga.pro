QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

load(qt_config)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    beziercurvepath.cpp \
    bullet.cpp \
    divingenemy.cpp \
    enemy.cpp \
    enemybullet.cpp \
    enemyspiral.cpp \
    explosion.cpp \
    formationa.cpp \
    formationb.cpp \
    formationc.cpp \
    formationd.cpp \
    gameobj.cpp \
    gamescene.cpp \
    healthbar.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    meteor.cpp \
    meteorflow.cpp \
    player.cpp \
    path.cpp \
    rotatingenemy.cpp \
    shield.cpp \
    shootingenemy.cpp \
    straightlinepath.cpp \
    formation.cpp

HEADERS += \
    beziercurvepath.h \
    bullet.h \
    divingenemy.h \
    enemy.h \
    enemybullet.h \
    enemyspiral.h \
    explosion.h \
    formationa.h \
    formationb.h \
    formationc.h \
    formationd.h \
    gameobj.h \
    gamescene.h \
    healthbar.h \
    item.h \
    mainwindow.h \
    meteor.h \
    meteorflow.h \
    player.h \
    path.h \
    rotatingenemy.h \
    shield.h \
    shootingenemy.h \
    straightlinepath.h \
    formation.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
