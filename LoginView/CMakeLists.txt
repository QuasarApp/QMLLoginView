#
# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.5)

project(LoginView LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LOGIN_VIEW_LIBRARY ON)

include(${CMAKE_CURRENT_SOURCE_DIR}/../CMake/ProjectOut.cmake)

find_package(Qt5 COMPONENTS Core Quick Xml REQUIRED)

file(GLOB SOURCE_CPP "src/*.cpp" "src/*.qrc")

add_library(${PROJECT_NAME} SHARED ${SOURCE_CPP})

target_compile_definitions(LoginView
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Quick Qt5::Xml)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src" CACHE STRING "Qt Creator extra qml import paths")
