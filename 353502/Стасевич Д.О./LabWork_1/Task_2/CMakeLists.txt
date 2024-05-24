cmake_minimum_required(VERSION 3.27)
project(lab_1_task_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab_1_task_2 main.cpp
        mainwindow/mainwindow.cpp
        mainwindow/mainwindow.h
        mainwindow/mainwindow.ui
        mainwindow/paintscene.cpp
        mainwindow/paintscene.h
        figures/baseFigure.cpp
        figures/baseFigure.h
        figures/polygon/polygon.cpp
        figures/polygon/polygon.h
        figures/straightPolygon/straightPolygon.cpp
        figures/straightPolygon/straightPolygon.h
        figures/star/star.cpp
        figures/star/star.h
        figures/custom/custom.cpp
        figures/custom/custom.h
)
target_link_libraries(lab_1_task_2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

