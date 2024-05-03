QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base.cpp \
    circle.cpp \
    main.cpp \
    mainwindow.cpp \
    rectungle.cpp \
    romb.cpp \
    trungle.cpp

HEADERS += \
    base.h \
    circle.h \
    mainwindow.h \
    rectungle.h \
    romb.h \
    trungle.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Lab1_Task2_en_US.ts
CONFIG += release
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
