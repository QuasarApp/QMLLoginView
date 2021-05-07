#
# Copyright (C) 2018-2021 Yankovich Andrei (EndrII).
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.5)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DLOGIN_VIEW_LIBRARY)

file(GLOB SOURCE_CPP "src/*.cpp" "src/*.qrc")

add_library(${PROJECT_NAME} ${SOURCE_CPP})

target_compile_definitions(LoginView
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Xml)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(LANGS ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_languages/en.ts
          ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_languages/ru.ts
          ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_languages/ja.ts
          ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_languages/tr.ts
          ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_languages/uk.ts)


prepareQM( ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR} "${LANGS}")

set(QML_IMPORT_PATH ${QML_IMPORT_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/src" CACHE STRING "" FORCE)
