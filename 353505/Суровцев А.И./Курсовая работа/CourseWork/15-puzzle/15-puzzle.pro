QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chain15.cpp \
    client_part.cpp \
    datainput.cpp \
    main.cpp \
    mainwindow.cpp \
    puzzle15.cpp \
    puzzlesolver.cpp \
    puzzleview.cpp \
    tile.cpp \
    timsort.cpp

HEADERS += \
    chain15.h \
    client_part.h \
    datainput.h \
    mainwindow.h \
    puzzle15.h \
    puzzlesolver.h \
    puzzleview.h \
    tile.h \
    timsort.h

FORMS += \
    datainput.ui \
    mainwindow.ui \
    puzzle15.ui

RESOURCES += \
    pictures

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
