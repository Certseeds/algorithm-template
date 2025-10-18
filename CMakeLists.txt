cmake_minimum_required(VERSION 3.16.6)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 13)
set(PROJECT_VERSION_PATCH 0) # delete endsWith strs when master merge dev

project(algorithm_template
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
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/2021F)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party)

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
