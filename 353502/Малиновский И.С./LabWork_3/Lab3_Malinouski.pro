QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Task_1/task1.cpp \
    Task_2/task2.cpp \
    Task_3/task3.cpp \
    Task_4/task4.cpp \
    Task_5/task5.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Task_1/task1.h \
    Task_2/task2.h \
    Task_3/task3.h \
    Task_4/task4.h \
    Task_5/task5.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
