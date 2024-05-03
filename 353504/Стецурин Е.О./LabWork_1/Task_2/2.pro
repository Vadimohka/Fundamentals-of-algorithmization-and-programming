QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ellips.cpp \
    figuredraw.cpp \
    inputdialogs.cpp \
    krug.cpp \
    main.cpp \
    mainwindow.cpp \
    mykvadrat.cpp \
    myrectangle.cpp \
    paintscene.cpp \
    romb.cpp \
    shestiugolnik.cpp \
    treugolnik.cpp \
    zvezda.cpp

HEADERS += \
    ellips.h \
    figure.h \
    inputdialogs.h \
    krug.h \
    mainwindow.h \
    mykvadrat.h \
    myrectangle.h \
    paintscene.h \
    romb.h \
    shestiugolnik.h \
    treugolnik.h \
    zvezda.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
