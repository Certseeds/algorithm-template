cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_disjoint_set LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(${PROJECT_NAME}_lib ${LIB_WAY} ${CMAKE_CURRENT_SOURCE_DIR}/disjoint_set.cpp)
target_link_libraries(${PROJECT_NAME}_lib PRIVATE algorithm_template_INCLUDE)

enable_testing()
set(dependencies 684 200 130 399 1361)
LIST(TRANSFORM dependencies PREPEND leetcode_)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} ${PROJECT_NAME}_lib algorithm_template_INCLUDE)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
    unset(elementName)
endforeach ()
unset(dependencies)

add_executable(${PROJECT_NAME}_lib_set_linkedlist ${CMAKE_CURRENT_SOURCE_DIR}/disjoint_set_linkedlist.cpp)
target_link_libraries(${PROJECT_NAME}_lib_set_linkedlist PRIVATE algorithm_template_INCLUDE)