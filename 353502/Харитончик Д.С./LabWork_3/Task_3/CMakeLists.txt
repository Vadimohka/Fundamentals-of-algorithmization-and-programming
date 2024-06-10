cmake_minimum_required(VERSION 3.28)
project(Lab3_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/System/Volumes/Data/Users/denisharitonciksergeevic/Qt/6.8.0/macos/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab3_3 main.cpp)
target_link_libraries(Lab3_3
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

