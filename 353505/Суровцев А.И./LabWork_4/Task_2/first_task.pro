QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    binary_power.cpp \
    binary_search.cpp \
    heap_sort.cpp \
    interpolation_sort.cpp \
    main.cpp \
    mainwindow.cpp \
    merge_sort.cpp \
    quick_sort.cpp

HEADERS += \
    binary_power.h \
    binary_search.h \
    heap_sort.h \
    interpolation_sort.h \
    mainwindow.h \
    merge_sort.h \
    quick_sort.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
