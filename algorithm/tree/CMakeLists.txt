cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_tree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies traverse huffman)

set(leetcode_order 94 95 96 98 100)
LIST(APPEND leetcode_order 104 226 530 559 589)
LIST(APPEND leetcode_order 590 617 654 669 700)
LIST(APPEND leetcode_order 701 144 145 102 101)
LIST(APPEND leetcode_order 112 235 653 so_32 so_26)
LIST(APPEND leetcode_order 113 426 so_54 114 230)
LIST(APPEND leetcode_order unknown 543 199 814 872)
LIST(APPEND leetcode_order 894 897 938 965 993)
LIST(APPEND leetcode_order 1008 1022 1038 1104 1261)
LIST(APPEND leetcode_order 1302 1315 1325 1367 1372)
LIST(TRANSFORM leetcode_order PREPEND leetcode_)

set(dependencies ${dependencies} ${leetcode_order})

unset(leetcode_order)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName}
                   ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} algorithm_template_INCLUDE)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/RBTree)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/avl)
