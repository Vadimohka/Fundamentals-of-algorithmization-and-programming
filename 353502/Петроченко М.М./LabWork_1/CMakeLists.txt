cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/acryoz/Qt/5.15.16/gcc_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled task1/src/main.cpp
        task1/src/rectangle.cpp
        task1/headers/rectangle.h
        task1/src/rectangle.ui
        task1/src/plane.cpp
        task1/headers/plane.h
        task1/src/plane.ui
)

add_executable(task2
        task2/src/main.cpp
        task2/src/mainwindow.cpp
        task2/headers/mainwindow.h
        task2/src/MainWindow.ui
        task2/src/Triangle.cpp
        task2/headers/Triangle.h
        task2/src/figure.cpp
        task2/headers/figure.h
        task2/src/canvas.cpp
        task2/headers/canvas.h
        task2/src/canvas.ui
        task2/src/redactarea.cpp
        task2/headers/redactarea.h
        task2/src/redactarea.ui
        task2/src/Rectangle.cpp
        task2/headers/Rectangle.h
        task2/src/Circle.cpp
        task2/headers/Circle.h
        task2/src/Square.cpp
        task2/headers/Square.h
        task2/src/Hexagon.cpp
        task2/headers/Hexagon.h
        task2/src/Rhombus.cpp
        task2/headers/Rhombus.h
        task2/src/Pentagram.cpp
        task2/headers/Pentagram.h
        task2/src/Octagram.cpp
        task2/headers/Octagram.h
        task2/src/Hexagram.cpp
        task2/headers/Hexagram.h
        task2/src/Pentagon.cpp
        task2/headers/Pentagon.h

)
target_link_libraries(untitled
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

target_link_libraries(task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
