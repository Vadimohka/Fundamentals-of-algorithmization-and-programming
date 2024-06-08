QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#INCLUDEPATH += /home/arina/SFML/SFML-2.6.1/include/SFML
#LIBS += -L/home/arina/SFML/SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += \
    drawer.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    drawer.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
