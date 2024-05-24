cmake_minimum_required(VERSION 3.27)
project(first)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/dmitry/Qt/6.6.1/gcc_64/lib/cmake/Qt6")

set(SOURCE
        source/main.cpp
        source/MainWindow.cpp
        source/Boat.cpp
        source/Flag.cpp
        source/Button.cpp
)
set(HEADER
        header/MainWindow.h
        header/Flag.h
        header/Boat.h
        header/Button.h
)

add_executable(first
        ${SOURCE}
        ${HEADER}
)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


target_include_directories(first
        PUBLIC
        header
)

target_link_libraries(first
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

