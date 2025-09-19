cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_associative_container LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies)

set(leetcode_order 888 890 893 1409 914)
list(APPEND leetcode_order 929 961 1002 1078 1122)
list(APPEND leetcode_order 1128 1160)
LIST(TRANSFORM leetcode_order PREPEND leetcode_)

set(dependencies ${dependencies} ${leetcode_order})

unset(leetcode_order)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    target_link_libraries(${PROJECT_NAME}_${elementName} CS203_DSAA_template_INCLUDE)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

