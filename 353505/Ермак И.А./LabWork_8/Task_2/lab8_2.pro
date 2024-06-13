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
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/HeapArray/release/ -lHeapArray
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/HeapArray/debug/ -lHeapArray
else:unix: LIBS += -L$$PWD/HeapArray/ -lHeapArray

INCLUDEPATH += $$PWD/HeapArray/include
DEPENDPATH += $$PWD/HeapArray/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/HeapList/release/ -lHeapList
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/HeapList/debug/ -lHeapList
else:unix: LIBS += -L$$PWD/HeapList/ -lHeapList

INCLUDEPATH += $$PWD/HeapList/include
DEPENDPATH += $$PWD/HeapList/include
