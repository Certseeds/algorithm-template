cmake_minimum_required(VERSION 3.16.6)
set(PROJECT_ORDER lab_01)
project(CS203_${PROJECT_ORDER})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies A B C D E F)
foreach (elementName IN LISTS dependencies)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_ORDER}_${elementName})
endforeach ()
unset(dependencies)
