cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_AVL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/avl.cpp)
target_link_libraries(${PROJECT_NAME}
                      algorithm_template_INCLUDE)

#add_test(${PROJECT_NAME}_CTEST ${PROJECT_NAME})
