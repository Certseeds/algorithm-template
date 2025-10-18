cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_INCLUDE LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} INTERFACE Catch2::Catch2WithMain)
target_compile_definitions(${PROJECT_NAME} INTERFACE ALGORITHM_TEST_MACRO)