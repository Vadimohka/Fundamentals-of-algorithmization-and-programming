QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Вы можете сделать так, чтобы ваш код не компилировался, если он использует устаревшие API.
# Для этого раскомментируйте следующую строку.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # отключает все API, устаревшие до Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

#//LIBS += -L/home/ubuntu/Qt/QT\ lab\ с2/lab8/Task_2_1/build-HeapArray-Desktop_Qt_6_6_1_GCC_64bit-Debug -lHeapArray
#LIBS += -L/home/ubuntu/Qt/QT\ lab\ с2/lab8/Task_2_1/build-HeapList-Desktop_Qt_6_6_1_GCC_64bit-Debug -lHeapList



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/release/ -lHeapArray
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/debug/ -lHeapArray
else:unix: LIBS += -L$$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/ -lHeapArray

INCLUDEPATH += $$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug
DEPENDPATH += $$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/release/libHeapArray.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/debug/libHeapArray.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/release/HeapArray.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/debug/HeapArray.lib
else:unix: PRE_TARGETDEPS += $$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/libHeapArray.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-HeapList-Desktop_Qt_6_6_2_GCC_64bit-Debug/release/ -lHeapList
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-HeapList-Desktop_Qt_6_6_2_GCC_64bit-Debug/debug/ -lHeapList
else:unix: LIBS += -L$$PWD/build-HeapList-Desktop_Qt_6_6_2_GCC_64bit-Debug/ -lHeapList

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/release/ -lHeapArray
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/debug/ -lHeapArray
else:unix: LIBS += -L$$PWD/build-HeapArray-Desktop_Qt_6_6_2_GCC_64bit-Debug/ -lHeapArray

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-HeapList-Desktop_Qt_6_6_2_GCC_64bit-Debug/release/ -lHeapList
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-HeapList-Desktop_Qt_6_6_2_GCC_64bit-Debug/debug/ -lHeapList
else:unix: LIBS += -L$$PWD/build-HeapList-Desktop_Qt_6_6_2_GCC_64bit-Debug/ -lHeapList

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''
