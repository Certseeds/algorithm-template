cmake_minimum_required(VERSION 3.16.6)
project(CS203_CATCH2_LIB)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set("BUILD_${LIB_WAY}_LIBS" YES)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/catch2)