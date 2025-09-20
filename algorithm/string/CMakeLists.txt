cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_string LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()

set(dependencies 3 6 8 12 13)
LIST(APPEND dependencies 14 22 38 344 535)
LIST(APPEND dependencies 657 387 383 so_05 242)
LIST(APPEND dependencies so_58 709 763 771 784)
LIST(APPEND dependencies 1324 1328 1358 1366 1370)
LIST(APPEND dependencies 1392 1408)
LIST(TRANSFORM dependencies PREPEND leetcode_)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} algorithm_template_INCLUDE)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
    unset(elementName)
endforeach ()
unset(dependencies)

