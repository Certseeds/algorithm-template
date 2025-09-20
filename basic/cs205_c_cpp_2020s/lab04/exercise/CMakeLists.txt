cmake_minimum_required(VERSION 3.10)
project(${PROJECT_NAME}_lab04_exercise)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

add_executable(${PROJECT_NAME}_01 lab04_01.cpp)
add_executable(${PROJECT_NAME}_02 lab04_02.cpp)
add_executable(${PROJECT_NAME}_03 lab04_03.cpp)
add_executable(${PROJECT_NAME}_test test_lab04.cpp)

target_link_libraries(${PROJECT_NAME}_01 PUBLIC ${PROJECT_NAME}_pizza)
target_link_libraries(${PROJECT_NAME}_02 PUBLIC ${PROJECT_NAME}_CandyBar)
target_link_libraries(${PROJECT_NAME}_test PUBLIC algorithm_template_INCLUDE
                      ${PROJECT_NAME}_pizza
                      ${PROJECT_NAME}_CandyBar)

# target_link_libraries(lab04)