cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_list LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies 2 19 21 23 24)
LIST(APPEND dependencies 25 61 82 83 86)
LIST(APPEND dependencies 109 92 146 206 so_06)
LIST(APPEND dependencies so_35 141 203 so_18 so_22)
LIST(APPEND dependencies 160 876 1409)
LIST(TRANSFORM dependencies PREPEND leetcode_)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    target_link_libraries(${PROJECT_NAME}_${elementName} CS203_DSAA_template_INCLUDE)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
    unset(elementName)
endforeach ()
unset(dependencies)

