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
    -L/home/egor1111/Лабы/LabWork_8/Task_2/BinaryHeapArrayLib -lBinaryHeapArrayLib \
    -L/home/egor1111/Лабы/LabWork_8/Task_2/BinaryHeapByListLib -lBinaryHeapByListLib


SOURCES += \
    # binaryheap.cpp \
    # binaryheapbylist.cpp \
    # list.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    # binaryheap.h \
    # binaryheapbylist.h \
    list.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
