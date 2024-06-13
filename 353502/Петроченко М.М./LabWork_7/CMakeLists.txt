cmake_minimum_required(VERSION 3.27)
project(lab7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/acryoz/Qt/5.15.17/gcc_64/lib/cmake/Qt5Charts")

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        Charts
)

add_executable(lab7 src/main.cpp
        src/queue.h
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
)
add_executable(task2 lib_bst/main.cpp
        lib_bst/avl.h
        lib_bst/graphview.cpp
        lib_bst/graphview.h
        lib_bst/mainwindow.cpp
        lib_bst/mainwindow.h
        lib_bst/mainwindow.ui
)

add_executable(task3 task3/hashtable.h
        task3/TaskSolver.cpp
        task3/TaskSolver.h
        task3/mainwindow.cpp
        task3/mainwindow.h
        task3/mainwindow.ui
        task3/main.cpp)

add_executable(task5 task5/deque.h
        task5/mainwindow.cpp
        task5/mainwindow.h
        task5/mainwindow.ui
        task5/main.cpp)
add_executable(task4 task4/HashTable.h
        task4/mainwindow.cpp
        task4/mainwindow.h
        task4/mainwindow.ui
        task4/main.cpp
)
target_link_libraries(lab7
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
target_link_libraries(task5
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
target_link_libraries(task4
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Charts
)
