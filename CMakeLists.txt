#
# Copyright (C) 2018-2021 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.5)
project(LoginView LANGUAGES CXX)
if(TARGET ${PROJECT_NAME})
  message("The ${PROJECT_NAME} arledy included in main Project")
  return()
endif()


if (NOT DEFINED LOGINVIEW_EXAMPLES)
    set(LOGINVIEW_EXAMPLES ON)

    if (DEFINED TARGET_PLATFORM_TOOLCHAIN)
        if (${TARGET_PLATFORM_TOOLCHAIN} STREQUAL "wasm32")
            set(LOGINVIEW_EXAMPLES OFF)
        endif()
    endif()

    if (ANDROID)
        set(LOGINVIEW_EXAMPLES OFF)
    endif()

endif()

include(CMake/QuasarApp.cmake)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Xml REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Xml REQUIRED)

# Add sub directories
add_subdirectory(LoginView)

if (LOGINVIEW_EXAMPLES)
    add_subdirectory(example)
endif()


initAll()

addDoc(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf)
