QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_element_window.cpp \
    add_type_window.cpp \
    element.cpp \
    main.cpp \
    mainwindow.cpp \
    queue.cpp

HEADERS += \
    add_element_window.h \
    add_type_window.h \
    element.h \
    mainwindow.h \
    queue.h

FORMS += \
    add_element_window.ui \
    add_type_window.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
