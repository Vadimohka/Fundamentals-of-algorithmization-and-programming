cmake_minimum_required(VERSION 3.28)
project(lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/acryoz/Qt/5.15.17/gcc_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(task1 task1/main.cpp
        task1/mainwindow.cpp
        task1/mainwindow.h
        task1/mainwindow.ui
        task1/converter.cpp
        task1/converter.h
)
add_executable(task2 task2/main.cpp
        task2/ackerman.cpp
        task2/ackerman.h
        task2/mainwindow.cpp
        task2/mainwindow.h
        task2/mainwindow.ui
)

add_executable(task3 task3/converter.cpp
        task3/converter.h
        task3/main.cpp
        task3/mainwindow.cpp
        task3/mainwindow.h
        task3/mainwindow.ui)

add_executable(task4 task4/main.cpp
        task4/hanoi.cpp
        task4/hanoi.h
        task4/mainwindow.ui
        task4/mainwindow.cpp
        task4/mainwindow.h)

add_executable(task5 task5/main.cpp
        task5/mainwindow.ui
        task5/mainwindow.cpp
        task5/mainwindow.h
        task5/counter.cpp
        task5/counter.h)
target_link_libraries(task1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

target_link_libraries(task2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
target_link_libraries(task3
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
target_link_libraries(task4
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
target_link_libraries(task5
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
