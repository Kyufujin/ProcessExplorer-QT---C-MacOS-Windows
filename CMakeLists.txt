cmake_minimum_required(VERSION 3.16)

project(ProcessExplorer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_FEATURE_vulkan NO)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    message(STATUS "Configuring for macOS")
    if(${CMAKE_SYSTEM_VERSION} VERSION_GREATER_EQUAL "12.0")
        message(STATUS "macOS version is 12.0 or newer")
        add_subdirectory(macOS)
    else()
        message(FATAL_ERROR "macOS version is too old. Minimum required is 12.0")
    endif()
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    message(STATUS "Configuring for Windows")
    add_subdirectory(Windows)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()
