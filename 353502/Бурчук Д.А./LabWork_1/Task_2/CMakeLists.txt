cmake_minimum_required(VERSION 3.27)
project(Lab1Task2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab1Task2 main.cpp
        Sources/Figures/Figure.cpp
        Headers/Figure.h
        Sources/Figures/Circle.cpp
        Headers/Circle.h
        Sources/Figures/Rectangle.cpp
        Headers/Rectangle.h
        Sources/Figures/Square.cpp
        Headers/Square.h
        Sources/MyWidget.cpp
        Headers/MyWidget.h
        Sources/Figures/Rhombus.cpp
        Headers/Rhombus.h
        Sources/Figures/Hexagon.cpp
        Headers/Hexagon.h
        Sources/Figures/Line.cpp
        Headers/Line.h
        Sources/Figures/BernoulliLemniscate.cpp
        Headers/BernoulliLemniscate.h
        Sources/Figures/Octagon.cpp
        Headers/Octagon.h
        Sources/Figures/Star.cpp
        Headers/Star.h
        Sources/Figures/Triangle.cpp
        Headers/Triangle.h
)

target_link_libraries(Lab1Task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

