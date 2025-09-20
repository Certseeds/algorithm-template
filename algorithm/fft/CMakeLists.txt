cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_fft LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies unfft fft)
foreach (elementName IN LISTS dependencies)
    add_library(${PROJECT_NAME}_${elementName} ${LIB_WAY}
                ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    set(CMAKE_CXX_STANDARD 17)
    add_executable(${PROJECT_NAME}_${elementName}_test
                   ${CMAKE_CURRENT_SOURCE_DIR}/fft_test.cpp)
    target_compile_definitions(${PROJECT_NAME}_${elementName}_test PRIVATE ALGORITHM_TEST_MACRO)
    target_link_libraries(${PROJECT_NAME}_${elementName}_test ${PROJECT_NAME}_${elementName} algorithm_template_INCLUDE)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName}_test)
    set(CMAKE_CXX_STANDARD 11)
endforeach ()
unset(dependencies)
