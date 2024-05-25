QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    \
    model/gamemodel.cpp \
    model/game.cpp \
    model/enemy.cpp \
    model/exception.cpp \
    \
    model/turrets/turret.cpp \
    model/turrets/standardattackturret.cpp \
    model/turrets/granadeturret.cpp \
    model/turrets/comboturret.cpp \
    model/turrets/splitturret.cpp \
    model/turrets/slowtimeturret.cpp \
    \
    controller/controller.cpp \
    controller/initialscreencontroller.cpp \
    controller/gamescreencontroller.cpp \
    controller/setmapscreencontroller.cpp \
    controller/tutorialscreencontroller.cpp \
    \
    view/mainwindow.cpp \
    view/mainwindowview.cpp \
    \
    view/hud/infobox.cpp \
    view/hud/iconbutton.cpp \
    view/hud/standardbutton.cpp \
    view/hud/modal.cpp \
    view/hud/errormodal.cpp \
    view/hud/popupselectoritem.cpp \
    view/hud/gametitle.cpp \
    \
    view/screens/gameScreen/gamescene.cpp \
    view/screens/gameScreen/enemyitem.cpp \
    view/screens/gameScreen/turretitem.cpp \
    view/screens/gameScreen/turretselector.cpp \
    view/screens/gameScreen/turretinfospanel.cpp \
    view/screens/gameScreen/turretradiuspreview.cpp \
    \
    view/screens/gameScreen/map/gridfield.cpp \
    view/screens/gameScreen/map/gridcell.cpp \
    \
    view/screens/gameScreen/modals/pausemodal.cpp \
    view/screens/gameScreen/modals/lostwonmodal.cpp \
    \
    view/screens/gameScreen/spawnable/projectile.cpp \
    view/screens/gameScreen/spawnable/bullet.cpp \
    view/screens/gameScreen/spawnable/granade.cpp \
    view/screens/gameScreen/spawnable/specialeffect.cpp \
    view/screens/gameScreen/spawnable/explosion.cpp \
    \
    view/screens/initialScreen/initialscreenscene.cpp \
    \
    view/screens/setMapScreen/setmapgrid.cpp \
    view/screens/setMapScreen/setmapscene.cpp \
    view/screens/setMapScreen/setmapcell.cpp \
    view/screens/setMapScreen/cellselector.cpp \
    \
    view/screens/tutorialScreen/tutorialscene.cpp \
    view/screens/tutorialScreen/tutorialcontent.cpp

HEADERS += \
    app/routes.h \
    app/shortcuts.h \
    \
    model/pathcell.h \
    model/position.h \
    model/gamemodel.h \
    model/game.h \
    model/sharedptr.h \
    model/mylist.h \
    model/enemy.h \
    model/exception.h \
    model/wave.h \
    \
    model/turrets/turret.h \
    model/turrets/standardattackturret.h \
    model/turrets/granadeturret.h \
    model/turrets/comboturret.h \
    model/turrets/splitturret.h \
    model/turrets/turrettype.h \
    model/turrets/slowtimeturret.h \
    \
    controller/controller.h \
    controller/initialscreencontroller.h \
    controller/gamescreencontroller.h \
    controller/setmapscreencontroller.h \
    controller/tutorialscreencontroller.h \
    \
    view/mainwindow.h \
    view/mainwindowview.h \
    \
    view/hud/infobox.h \
    view/hud/iconbutton.h \
    view/hud/standardbutton.h \
    view/hud/modal.h \
    view/hud/errormodal.h \
    view/hud/popupselectoritem.h \
    view/hud/gametitle.h \
    \
    view/screens/gameScreen/gamescene.h \
    view/screens/gameScreen/enemyitem.h \
    view/screens/gameScreen/turretitem.h \
    view/screens/gameScreen/turretselector.h \
    view/screens/gameScreen/turretinfospanel.h \
    view/screens/gameScreen/turretradiuspreview.h \
    \
    view/screens/gameScreen/map/gridfield.h \
    view/screens/gameScreen/map/gridcell.h \
    view/screens/gameScreen/map/gridcelltype.h \
    \
    view/screens/gameScreen/modals/pausemodal.h \
    view/screens/gameScreen/modals/lostwonmodal.h \
    \
    view/screens/gameScreen/spawnable/projectile.h \
    view/screens/gameScreen/spawnable/bullet.h \
    view/screens/gameScreen/spawnable/granade.h \
    view/screens/gameScreen/spawnable/specialeffect.h \
    view/screens/gameScreen/spawnable/explosion.h \
    \
    view/screens/initialScreen/initialscreenscene.h \
    \
    view/screens/setMapScreen/setmapscene.h \
    view/screens/setMapScreen/setmapgrid.h \
    view/screens/setMapScreen/setmapcell.h \
    view/screens/setMapScreen/cellselector.h  \
    \
    view/screens/tutorialScreen/tutorialscene.h \
    view/screens/tutorialScreen/tutorialcontent.h




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc
