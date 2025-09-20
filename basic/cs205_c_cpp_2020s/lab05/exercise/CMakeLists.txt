cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME}_lab05_exercise)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}_01 lab05_01.cpp)
add_executable(${PROJECT_NAME}_02 lab05_02.cpp)
add_executable(${PROJECT_NAME}_03 lab05_03.cpp)
add_executable(${PROJECT_NAME}_04 lab05_04.cpp)

add_executable(${PROJECT_NAME}_test test_lab05.cpp)
target_link_libraries(${PROJECT_NAME}_test PUBLIC algorithm_template_INCLUDE)

# target_link_libraries(lab05)