QT       += core gui
QT+=charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    delete.cpp \
    download.cpp \
    download_nv.cpp \
    encryption.cpp \
    main.cpp \
    mainwindow.cpp \
    statistic.cpp \
    update.cpp

HEADERS += \
    delete.h \
    download.h \
    download_nv.h \
    encryption.h \
    mainwindow.h \
    statistic.h \
    update.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    decrypt_downloadv2.txt \
    decrypt_for_download.txt \
    decrypt_uninstall.txt \
    decrypt_upgrade.txt \
    logs.txt
