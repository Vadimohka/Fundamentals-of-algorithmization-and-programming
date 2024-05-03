QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Line.cpp \
    circle.cpp \
    customscene.cpp \
    ellipse.cpp \
    figure.cpp \
    hexagon.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    romb.cpp \
    square.cpp \
    star5.cpp \
    star6.cpp \
    star8.cpp \
    triangle2.cpp \
    triangle90.cpp

HEADERS += \
    Line.h \
    circle.h \
    customscene.h \
    ellipse.h \
    figure.h \
    hexagon.h \
    mainwindow.h \
    rectangle.h \
    romb.h \
    square.h \
    star5.h \
    star6.h \
    star8.h \
    triangle2.h \
    triangle90.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourse.qrc
