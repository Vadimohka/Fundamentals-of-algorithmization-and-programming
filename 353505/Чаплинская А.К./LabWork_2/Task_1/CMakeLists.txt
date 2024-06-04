cmake_minimum_required(VERSION 3.24)
project(Lab1T1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab1T1 main.cpp mainWindow/mainWindow.cpp mainWindow/mainWindow.h workWithDate/workWithDate.cpp workWithDate/workWithDate.h)
target_link_libraries(Lab1T1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

