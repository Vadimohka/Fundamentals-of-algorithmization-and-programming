cmake_minimum_required(VERSION 3.27)
project(telega)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
  Core
  Gui
  Widgets
  REQUIRED)

add_executable(telega main.cpp
        main_window/main_window.cpp
        main_window/main_window.h
        main_window/main_window.ui
        src/background.cpp
        src/background.h
        src/moving_rect.cpp
        src/moving_rect.h
        src/waggon.cpp
        src/waggon.h)
target_link_libraries(telega
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
)

