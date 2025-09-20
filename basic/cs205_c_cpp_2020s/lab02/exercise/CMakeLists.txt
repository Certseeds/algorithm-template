cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_lab02_exercise)


add_executable(${PROJECT_NAME}_test test_lab02.cpp)
add_executable(${PROJECT_NAME}_01 lab02_01.cpp)
add_executable(${PROJECT_NAME}_02 lab02_02.cpp)
add_executable(${PROJECT_NAME}_03 lab02_03.cpp)
target_link_libraries(${PROJECT_NAME}_test PUBLIC algorithm_template_INCLUDE)