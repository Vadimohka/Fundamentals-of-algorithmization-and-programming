QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h \

FORMS += \
    mainwindow.ui

unix:!macx: LIBS += -L$$PWD/Static/build/Desktop_Qt_6_6_1_GCC_64bit-Debug/ -lStatic

INCLUDEPATH += $$PWD/Static
DEPENDPATH += $$PWD/Static

unix:!macx: PRE_TARGETDEPS += $$PWD/Static/build/Desktop_Qt_6_6_1_GCC_64bit-Debug/libStatic.a

unix:!macx: LIBS += -L$$PWD/Dynamic/build/Desktop_Qt_6_6_1_GCC_64bit-Debug/ -lDynamic

INCLUDEPATH += $$PWD/Dynamic
DEPENDPATH += $$PWD/Dynamic
