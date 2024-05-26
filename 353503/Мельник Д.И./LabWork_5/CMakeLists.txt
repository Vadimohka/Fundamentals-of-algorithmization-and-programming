cmake_minimum_required(VERSION 3.16)

project(LabWork_5 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/dmitry/Qt/6.6.1/gcc_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
qt_standard_project_setup()


add_library(string SHARED Task_2/String.cpp)

qt_add_executable(Task_2
  Task_2/main.cpp Task_2/mainwindow.cpp Task_2/mainwindow.ui
)
target_link_libraries(Task_2 PRIVATE Qt6::Widgets string)

qt_add_executable(Task_3
  Task_3/main.cpp Task_3/mainwindow.cpp Task_3/mainwindow.ui
)
target_link_libraries(Task_3 PRIVATE Qt6::Widgets)

