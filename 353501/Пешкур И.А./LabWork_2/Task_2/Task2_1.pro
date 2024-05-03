QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    errormenu.cpp \
    main.cpp \
    mainwindow.cpp \
    nichevo.cpp \
    order.cpp \
    restarauntmenu.cpp \
    ura.cpp

HEADERS += \
    errormenu.h \
    mainwindow.h \
    nichevo.h \
    order.h \
    restarauntmenu.h \
    ura.h

FORMS += \
    errormenu.ui \
    mainwindow.ui \
    nichevo.ui \
    restarauntmenu.ui \
    ura.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
