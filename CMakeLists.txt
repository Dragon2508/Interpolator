cmake_minimum_required(VERSION 3.14)
project(Interpolator)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Interpolator
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
    tablemodel.cpp
    tablemodel.h
    interpolator.cpp
    interpolator.h
    graphics.cpp
    graphics.h
)

target_link_libraries(Interpolator PRIVATE Qt5::Widgets)
