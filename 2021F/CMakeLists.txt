cmake_minimum_required(VERSION 3.16.6)
set(YEAR 2021)
set(SEMESTER FALL)

set(CMAKE_CXX_STANDARD 11)
project(CS203_DSAA_${YEAR}_${SEMESTER} LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
file(GLOB USER_LIBS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lab_*) # regex to find libs, more flexibility
foreach (elementName IN LISTS USER_LIBS_PATH)
    add_subdirectory(${elementName})
endforeach ()
unset(USER_LIBS_PATH)
