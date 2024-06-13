cmake_minimum_required(VERSION 3.27)
project(lab4)

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

add_executable(lab4 src/main.cpp
        src/mainwindow.cpp
        headers/mainwindow.h
        src/mainwindow.ui
        src/sortingalgs.cpp
        headers/sortingalgs.h
        src/binsearch.cpp
        headers/binsearch.h
        src/binpow.cpp
        headers/binpow.h
)

add_executable(lab4.5 src/main2.cpp
        lib/library.cpp
        lib/iterator.cpp
        src/mainwindow2.cpp
        headers/mainwindow2.h
        src/mainwindow2.ui
        lib/pair.cpp)

target_link_libraries(lab4
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
target_link_libraries(lab4.5
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

