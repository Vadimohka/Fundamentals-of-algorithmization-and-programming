QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    block.cpp \
    button.cpp \
    city.cpp \
    game.cpp \
    gui.cpp \
    log.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    unit.cpp \
    world.cpp

HEADERS += \
    block.h \
    button.h \
    city.h \
    game.h \
    gui.h \
    log.h \
    mainwindow.h \
    player.h \
    unit.h \
    world.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background_menu.qrc \
    game.qrc

DISTFILES += \
    Civilization.pro.user \
    README.md \
    resource/background_menu.png
