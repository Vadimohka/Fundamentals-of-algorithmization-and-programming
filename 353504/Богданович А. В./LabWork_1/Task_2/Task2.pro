QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Circle.cpp \
    Figure.cpp \
    Hexagon.cpp \
    Rectangle.cpp \
    Rhombus.cpp \
    Square.cpp \
    Star5Pntd.cpp \
    Star6Pntd.cpp \
    Star8Pntd.cpp \
    Trapezoid.cpp \
    Triangle.cpp \
    circledialog.cpp \
    hexagondialog.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangledialog.cpp \
    rhombusdialog.cpp \
    squaredialog.cpp \
    stardialog.cpp \
    trapezoiddialog.cpp \
    triangledialog.cpp

HEADERS += \
    Circle.h \
    Figure.h \
    Hexagon.h \
    Rectangle.h \
    Rhombus.h \
    Square.h \
    Star5Pntd.h \
    Star6Pntd.h \
    Star8Pntd.h \
    Trapezoid.h \
    Triangle.h \
    circledialog.h \
    hexagondialog.h \
    mainwindow.h \
    rectangledialog.h \
    rhombusdialog.h \
    squaredialog.h \
    stardialog.h \
    trapezoiddialog.h \
    triangledialog.h

FORMS += \
    circledialog.ui \
    hexagondialog.ui \
    mainwindow.ui \
    rectangledialog.ui \
    rhombusdialog.ui \
    squaredialog.ui \
    stardialog.ui \
    trapezoiddialog.ui \
    triangledialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
