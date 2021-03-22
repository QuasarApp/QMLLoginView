#
# Copyright (C) 2018-2021 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.5)
project(LoginViewMain)

if(NOT DEFINED LOGINVIEW_EXAMPLES)
    set (LOGINVIEW_EXAMPLES ON)
endif()

# Add sub directories
add_subdirectory(LoginView)

if (LOGINVIEW_EXAMPLES)
    add_subdirectory(example)
endif()
