QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# путь к заголовочным файлам библиотек
INCLUDEPATH += \
    ./BinaryHeapArrayLib \
    ./BinaryHeapByListLib

# полный путь к статической и динамической либам
LIBS += \
    -L/home/Projects/LabWork_8/Task_2/BinaryHeapArrayLib/build/Desktop_Qt_6_7_0-Debug -lBinaryHeapArrayLib \
    -L/home/Projects/LabWork_8/Task_2/BinaryHeapByListLib/build/Desktop_Qt_6_7_0-Debug -lBinaryHeapByListLib


SOURCES += \
    # binaryheap.cpp \
    # binaryheapbylist.cpp \
    # list.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    # binaryheap.h \
    # binaryheapbylist.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/BinaryHeapArrayLib/build/Desktop_Qt_6_7_0-Debug/release/ -lBinaryHeapArrayLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/BinaryHeapArrayLib/build/Desktop_Qt_6_7_0-Debug/debug/ -lBinaryHeapArrayLib
else:unix: LIBS += -L$$PWD/BinaryHeapArrayLib/build/Desktop_Qt_6_7_0-Debug/ -lBinaryHeapArrayLib

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/BinaryHeapByListLib/build/Desktop_Qt_6_7_0-Debug/release/ -lBinaryHeapByListLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/BinaryHeapByListLib/build/Desktop_Qt_6_7_0-Debug/debug/ -lBinaryHeapByListLib
else:unix: LIBS += -L$$PWD/BinaryHeapByListLib/build/Desktop_Qt_6_7_0-Debug/ -lBinaryHeapByListLib

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''
