QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle.cpp \
    circledialog.cpp \
    eightpointedstar.cpp \
    figure.cpp \
    fivepointedstar.cpp \
    hexagon.cpp \
    hexagondialog.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    rectangledialog.cpp \
    rhomb.cpp \
    rhombdialog.cpp \
    sixpointedstar.cpp \
    square.cpp \
    squaredialog.cpp \
    trapezoid.cpp \
    trapezoiddialog.cpp \
    triangle.cpp \
    triangledialog.cpp

HEADERS += \
    circle.h \
    circledialog.h \
    eightpointedstar.h \
    figure.h \
    fivepointedstar.h \
    hexagon.h \
    hexagondialog.h \
    mainwindow.h \
    rectangle.h \
    rectangledialog.h \
    rhomb.h \
    rhombdialog.h \
    sixpointedstar.h \
    square.h \
    squaredialog.h \
    trapezoid.h \
    trapezoiddialog.h \
    triangle.h \
    triangledialog.h

FORMS += \
    circledialog.ui \
    hexagondialog.ui \
    mainwindow.ui \
    rectangledialog.ui \
    rhombdialog.ui \
    squaredialog.ui \
    trapezoiddialog.ui \
    triangledialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
