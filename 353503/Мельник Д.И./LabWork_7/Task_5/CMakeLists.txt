cmake_minimum_required(VERSION 3.16)

project(Lab_7_5 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_PREFIX_PATH "/home/dmitry/Qt/6.6.1/gcc_64/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

qt_standard_project_setup()

enable_testing()

qt_add_executable(Lab_7_5
  main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
)

target_link_libraries(Lab_7_5 PRIVATE Qt6::Widgets)

