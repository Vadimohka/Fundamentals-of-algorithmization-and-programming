QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additemdialog.cpp \
    components.cpp \
    main.cpp \
    mainwindow.cpp \
    pricerangedialog.cpp \
    rangedialog.cpp \
    searchdialog.cpp \
    view_dialog.cpp

HEADERS += \
    additemdialog.h \
    components.h \
    mainwindow.h \
    pricerangedialog.h \
    rangedialog.h \
    searchdialog.h \
    view_dialog.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
