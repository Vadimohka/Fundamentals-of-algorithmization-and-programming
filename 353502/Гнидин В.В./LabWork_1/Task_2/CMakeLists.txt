cmake_minimum_required(VERSION 3.27)
project(risovalka)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
  Core
  Gui
  Widgets
  REQUIRED)

add_executable(risovalka main.cpp
        main_window.cpp
        main_window.h
        main_window.ui
        paintScene.cpp
        paintScene.h
        figures/base_figure.cpp
        figures/base_figure.h
        figures/npolygon.cpp
        figures/npolygon.h
        figures/nstar.cpp
        figures/nstar.h
)
target_link_libraries(risovalka
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
)

