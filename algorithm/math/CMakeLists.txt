cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_math LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies min_max_middle)

set(leetcode_order 9 29 43 50 60)
LIST(APPEND leetcode_order 118_119 169 217 263)
LIST(APPEND leetcode_order 268 283 338 343 372)
LIST(APPEND leetcode_order 401 414 461 728 781)
LIST(APPEND leetcode_order 136 75 883 1018 1185)
LIST(APPEND leetcode_order 670 1252 1362 1363 1390)
LIST(APPEND leetcode_order 1402)
LIST(TRANSFORM leetcode_order PREPEND leetcode_)

set(dependencies ${dependencies} ${leetcode_order})

unset(leetcode_order)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} CS203_DSAA_template_INCLUDE)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

