cmake_minimum_required(VERSION 3.16.6)
set(PROBLEM_ORDER B)
project(${PROJECT_NAME}_${PROBLEM_ORDER})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME}_test ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
target_compile_definitions(${PROJECT_NAME}_test PRIVATE ALGORITHM_TEST_MACRO)
target_link_libraries(${PROJECT_NAME}_test PRIVATE
                      algorithm_template_INCLUDE)
MESSAGE(STATUS "${PROJECT_NAME} from ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp")
add_test(${PROJECT_NAME}_CTEST ${PROJECT_NAME}_test)
set(CMAKE_CXX_STANDARD 11)
