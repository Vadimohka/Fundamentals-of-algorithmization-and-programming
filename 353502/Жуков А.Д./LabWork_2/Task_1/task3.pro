TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    binaryoperation.h \
    expression.h \
    function.h \
    number.h

SOURCES += \
    binaryoperation.cpp \
    function.cpp \
    number.cpp
