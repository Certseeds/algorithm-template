add_executable(${PROJECT_NAME}_test test_assignment_1.cpp)
target_link_libraries(${PROJECT_NAME}_test
                      PUBLIC
                      ${PROJECT_NAME}_lib
                      algorithm_template_INCLUDE)
