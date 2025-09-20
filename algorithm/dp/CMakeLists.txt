cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_dp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()

set(dependencies package divide_bar matrix_multiply)

set(leetcode_order 1143 5 10 44 45)
LIST(APPEND leetcode_order 63 62 64 70 746)
LIST(APPEND leetcode_order 97 322 509 1137 416)
LIST(APPEND leetcode_order 198 213 740 55 918)
LIST(APPEND leetcode_order 152 120 1567 1014 121)
LIST(APPEND leetcode_order 122 309 714 139 413)
LIST(APPEND leetcode_order 91 264 931 304 1314 221)
LIST(APPEND leetcode_order 516 300 174 376 643)
LIST(APPEND leetcode_order 392 72 518 377 279)
LIST(APPEND leetcode_order so_46 435 1025 1044 1277)
LIST(TRANSFORM leetcode_order PREPEND leetcode_)

set(dependencies ${dependencies} ${leetcode_order})

unset(leetcode_order)


foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} algorithm_template_INCLUDE)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE ALGORITHM_TEST_MACRO)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

