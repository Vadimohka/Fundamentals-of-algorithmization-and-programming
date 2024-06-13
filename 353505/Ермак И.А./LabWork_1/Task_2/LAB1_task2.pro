QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canva.cpp \
    circle.cpp \
    dialogcircle.cpp \
    dialogellipse.cpp \
    dialoghexagone.cpp \
    dialogrectangle.cpp \
    dialogsquare.cpp \
    dialogstar.cpp \
    dialogtriangle.cpp \
    ellipse.cpp \
    form.cpp \
    hexagone.cpp \
    main.cpp \
    mainwindow.cpp \
    paintscene.cpp \
    rectangle.cpp \
    square.cpp \
    star.cpp \
    triangle.cpp

HEADERS += \
    canva.h \
    circle.h \
    dialogcircle.h \
    dialogellipse.h \
    dialoghexagone.h \
    dialogrectangle.h \
    dialogsquare.h \
    dialogstar.h \
    dialogtriangle.h \
    ellipse.h \
    form.h \
    hexagone.h \
    mainwindow.h \
    paintscene.h \
    rectangle.h \
    square.h \
    star.h \
    triangle.h

FORMS += \
    canva.ui \
    dialogcircle.ui \
    dialogellipse.ui \
    dialoghexagone.ui \
    dialogrectangle.ui \
    dialogsquare.ui \
    dialogstar.ui \
    dialogtriangle.ui \
    mainwindow.ui

TRANSLATIONS += \
    LAB1_task2_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
