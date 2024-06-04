cmake_minimum_required(VERSION 3.5)

project(STS VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(STS
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}



        level.h level.cpp
        person.h person.cpp
        player.h player.cpp
        enemy.h enemy.cpp






        artefacts.h artefacts.cpp
        bittonsort.h bittonsort.cpp
        graph.h graph.cpp
        montecarlo.h montecarlo.cpp
        ufloid.h ufloid.cpp

        PixMaps.qrc
        savemenu.h savemenu.cpp savemenu.ui
        gamescene.h gamescene.cpp gamescene.ui
        gamelevelsscene.h gamelevelsscene.cpp gamelevelsscene.ui
        mainmenu.h mainmenu.cpp mainmenu.ui
        mainwindow.h mainwindow.cpp mainwindow.ui
        gamepoint.h gamepoint.cpp
        health.h health.cpp

        damage.h damage.cpp
        defence.h defence.cpp
        energy.h energy.cpp
        card.h card.cpp
        deck.h deck.cpp
        CardCharHDDE.h
        effects.h effects.cpp
        gamesceneview.h gamesceneview.cpp
        dialogshop.h dialogshop.cpp dialogshop.ui
        dialoglose.h dialoglose.cpp dialoglose.ui
        dialogwinmenu.h dialogwinmenu.cpp dialogwinmenu.ui
        dialogshowcards.h dialogshowcards.cpp dialogshowcards.ui








    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET STS APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(STS SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(STS
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(STS PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.STS)
endif()
set_target_properties(STS PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS STS
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(STS)
endif()
