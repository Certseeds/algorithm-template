cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_binary_search LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(${PROJECT_NAME}_basic_src ${LIB_WAY} ${CMAKE_CURRENT_SOURCE_DIR}/basic.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/basic.hpp)
target_include_directories(${PROJECT_NAME}_basic_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
set(dependencies basic triple_search rotate_array)

set(leetcode_order 35 4 33 162 34)
LIST(APPEND leetcode_order 69 81 153_154 so_53ii)
LIST(APPEND leetcode_order 1608 1237 1760)
LIST(TRANSFORM leetcode_order PREPEND leetcode_)

set(dependencies ${dependencies} ${leetcode_order})

unset(leetcode_order)


foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    target_link_libraries(${PROJECT_NAME}_${elementName} PRIVATE
                          CS203_DSAA_template_INCLUDE
                          ${PROJECT_NAME}_basic_src)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

