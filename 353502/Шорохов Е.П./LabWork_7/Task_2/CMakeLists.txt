cmake_minimum_required(VERSION 3.28)
project(LabWork_7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LabWork_7 main.cpp
        Deque/Deque.cpp
        Deque/Deque.h)

target_link_libraries(LabWork_7
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

add_executable(AWL
         awl.cpp
        AWL/Node.cpp
        AWL/Node.h
        AVL_MainWindow/MainWindow.cpp
        AVL_MainWindow/MainWindow.h)

target_link_libraries(AWL
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

add_executable(Hash
        hash.cpp
        hashTable/HashTable.h
        hashTable/HashTable.cpp)
target_link_libraries(Hash
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

