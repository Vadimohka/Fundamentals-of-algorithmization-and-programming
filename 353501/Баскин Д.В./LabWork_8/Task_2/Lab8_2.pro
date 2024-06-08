QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

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

unix|win32: LIBS += -L$$PWD/Array_BinHeap/ -larray_binheap

INCLUDEPATH += $$PWD/Array_BinHeap
DEPENDPATH += $$PWD/Array_BinHeap

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/Array_BinHeap/array_binheap.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/Array_BinHeap/libarray_binheap.a

unix|win32: LIBS += -L$$PWD/List_BinHeap/ -llist_binheap

INCLUDEPATH += $$PWD/List_BinHeap
DEPENDPATH += $$PWD/List_BinHeap
