cmake_minimum_required(VERSION 3.24)
project(Lab1T2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab1T2 main.cpp mainWindow/mainWindow.cpp mainWindow/mainWindow.h projects/projectClass.cpp projects/projectClass.h mainWindow/editWindow.cpp mainWindow/editWindow.h)
target_link_libraries(Lab1T2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

