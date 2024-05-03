TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        binaryoperation.cpp \
        main.cpp \
        number.cpp

HEADERS += \
    binaryoperation.h \
    expression.h \
    number.h
