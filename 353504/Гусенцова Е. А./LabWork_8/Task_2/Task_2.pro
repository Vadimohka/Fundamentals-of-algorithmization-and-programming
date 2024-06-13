QT += core gui
QT += widgets

CONFIG += c++11

TARGET = Task_2
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h

FORMS += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../HeapArray/release/ -lHeapArray
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../HeapArray/debug/ -lHeapArray
else:unix: LIBS += -L$$PWD/../HeapArray/ -lHeapArray

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../HeapList/release/ -lHeapList
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../HeapList/debug/ -lHeapList
else:unix: LIBS += -L$$PWD/../HeapList/ -lHeapList

INCLUDEPATH += $$PWD/../HeapArray
INCLUDEPATH += $$PWD/../HeapList

DEPENDPATH += $$PWD/../HeapArray
DEPENDPATH += $$PWD/../HeapList
