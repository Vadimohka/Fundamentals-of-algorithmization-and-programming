cmake_minimum_required(VERSION 3.27)
project(untitled5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/acryoz/Qt/5.15.16/gcc_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled5 t1/src/main.cpp
        t1/src/mainwindow.cpp
        t1/headers/mainwindow.h
        t1/src/mainwindow.ui
        t1/src/Date.cpp
        t1/headers/Date.h
        t1/src/DateException.cpp
        t1/headers/DateException.h
        t1/src/QTableViewModel.cpp
        t1/headers/QTableViewModel.h
        t1/src/inputpopup.cpp
        t1/headers/inputpopup.h
        t1/src/inputpopup.ui
        t1/src/files.cpp
        t1/headers/files.h)
add_executable(task2 t2/src/main.cpp
        t2/src/mainwindow.cpp
        t2/headers/mainwindow.h
        t2/src/mainwindow.ui
        t2/src/Candidate.cpp
        t2/headers/Candidate.h
        t2/src/Party.cpp
        t2/headers/Party.h
        t2/src/files.cpp
        t2/headers/files.h)

target_link_libraries(untitled5
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

target_link_libraries(task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
add_executable(task3 t3/src/main.cpp
        t3/headers/Expression.h
        t3/src/Number.cpp
        t3/headers/Number.h
        t3/src/BinaryExpression.cpp
        t3/headers/BinaryExpression.h)
