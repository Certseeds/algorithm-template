cmake_minimum_required(VERSION 3.16.6)
project(CS205_PROJECT_2020S LANGUAGES CXX)
if (COMPILER_SUPPORTS_CXX20)
    MESSAGE("ENABLE COMPILE ${PROJECT_NAME}")
    set(CMAKE_CXX_STANDARD 20) # Newest MSVC support C++20

    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})

    Output_variable(CMAKE_BUILD_TYPE)
    #set(OpenCV_LIBS "${OpenCV_DIR}/x64/vc16/lib")
    if (USE_OPENCV)
        Output_variable(OpenCV_FOUND)
        Output_Paths()
        find_package(OpenCV REQUIRED)
        Output_Paths()
        Output_variable(OpenCV_FOUND)
    endif ()
    if (OpenCV_FOUND)
        add_definitions(-D_HAVE_OPENCV_)
        MESSAGE("OpenCV MACRO ADDED")
    endif ()
    enable_testing()
    add_executable(${PROJECT_NAME}_test ${CMAKE_CURRENT_SOURCE_DIR}/matrix_test.cpp)
    target_link_libraries(${PROJECT_NAME}_test
                          PUBLIC
                          algorithm_template_INCLUDE
                          )
    IF (OpenCV_FOUND)
        target_link_libraries(${PROJECT_NAME}_test
                              PUBLIC
                              ${OpenCV_LIBS}
                              )
        MESSAGE("TARGET LINK OPENCV_LIBS")
    endif ()
    add_test(${PROJECT_NAME}_ctest ${PROJECT_NAME}_test)
else ()
endif ()