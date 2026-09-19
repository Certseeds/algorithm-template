cmake_minimum_required(VERSION 3.16.6)

set(PROJECT_VERSION_MAJOR 2026)
set(PROJECT_VERSION_MINOR 09)
set(PROJECT_VERSION_PATCH 19)

project(algorithm_template
        VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
        DESCRIPTION "Template for Algorithm Based on C++11 and Modern CMake"
        HOMEPAGE_URL "https://github.com/Certseeds/algorithm-template"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

string(TIMESTAMP time_str "%Y/%m/%d  %H:%M:%S")
MESSAGE(STATUS "Compiler In \n ${time_str}")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CMakeLists.txt)

find_package(GTest REQUIRED)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
file(GLOB USER_LIBS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lab_*) # regex to find libs, more flexibility
foreach (elementName IN LISTS USER_LIBS_PATH)
    if (EXISTS ${elementName}/CMakeLists.txt)
        add_subdirectory(${elementName})
    else()
        MESSAGE("${elementName} is empty")
    endif ()
endforeach ()
unset(USER_LIBS_PATH)
