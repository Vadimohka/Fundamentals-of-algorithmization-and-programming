cmake_minimum_required(VERSION 3.27)
project(Laba_2_1)

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

add_executable(Laba_2_1 main.cpp
        dateService/dateHandler.h
        dateService/dateHandler.cpp
        mainWindow/mainWindow.h
        mainWindow/mainWindow.cpp)
target_link_libraries(Laba_2_1
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

