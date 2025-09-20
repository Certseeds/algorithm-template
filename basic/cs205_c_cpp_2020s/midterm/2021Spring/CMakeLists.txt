cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_Midterm_2021Spring LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(_List 1 2 3 4 5 _test)
foreach (element IN LISTS _List)
    add_executable(${PROJECT_NAME}${element}
                   ${CMAKE_CURRENT_SOURCE_DIR}/question${element}.cpp)
endforeach ()
unset(_List)
target_link_libraries(${PROJECT_NAME}_test PUBLIC algorithm_template_INCLUDE)
