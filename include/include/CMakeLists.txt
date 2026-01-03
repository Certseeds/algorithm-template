cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_INCLUDE LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

