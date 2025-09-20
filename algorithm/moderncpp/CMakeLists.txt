cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_moderncpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")


enable_testing()
set(dependencies 02 04 07)
foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName}
                   ${CMAKE_CURRENT_SOURCE_DIR}/chap${elementName}.cpp)
    # target_link_libraries(${PROJECT_NAME}_${elementName} algorithm_template_INCLUDE)
    target_link_libraries(${PROJECT_NAME}_${elementName} PUBLIC Threads::Threads)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)