cmake_minimum_required(VERSION 3.5)

project(Kursach_bank VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        registration_window.h registration_window.cpp registration_window.ui
        allusersfile.h allusersfile.cpp
        home_window.h home_window.cpp home_window.ui
        card.h card.cpp
        user.h user.cpp
        bank_meneger.h bank_meneger.cpp
        personal_data_window.h personal_data_window.cpp personal_data_window.ui
        sha256.h sha256.cpp
        luna.h luna.cpp
        bank_account.h bank_account.cpp
        transactions.h transactions.cpp
        card_rect.h card_rect.cpp
        register_new_card_window.h register_new_card_window.cpp register_new_card_window.ui
        card_data_window.h card_data_window.cpp card_data_window.ui
        add_money_window.h add_money_window.cpp add_money_window.ui
        transfer_money_window.h transfer_money_window.cpp transfer_money_window.ui
        pay_the_bill_window.h pay_the_bill_window.cpp pay_the_bill_window.ui
        blowfish.h blowfish.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Kursach_bank
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Kursach_bank APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Kursach_bank SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Kursach_bank
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Kursach_bank PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Kursach_bank PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Kursach_bank
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Kursach_bank)
endif()
