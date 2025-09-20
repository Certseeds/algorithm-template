cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_banker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
add_executable(${PROJECT_NAME}_test ${CMAKE_CURRENT_SOURCE_DIR}/banker.cpp)
target_link_libraries(${PROJECT_NAME}_test algorithm_template_INCLUDE)
target_compile_definitions(${PROJECT_NAME}_test PRIVATE ALGORITHM_TEST_MACRO)
MESSAGE(STATUS "${PROJECT_NAME} from ${CMAKE_CURRENT_SOURCE_DIR}/banker.cpp")
add_test(${PROJECT_NAME}_CTEST ${PROJECT_NAME}_test)
