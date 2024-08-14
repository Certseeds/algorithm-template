cmake_minimum_required(VERSION 3.16.6)
project(CS203_CATCH2_LIB)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set("BUILD_${LIB_WAY}_LIBS" YES)

Include(FetchContent)
CMAKE_CMP_0135()
set(CATCH2_URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.7.0.tar.gz)
set(CATCH2_HASH "f0cd2b73baf5e965a2d2430871f2c2cf")
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    FetchContent_Declare(
            Catch2
            URL ${CATCH2_URL}
            URL_HASH MD5=${CATCH2_HASH}
            SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/catch2
    )
else()
    FetchContent_Declare(
            Catch2
            URL ${CATCH2_URL}
            URL_HASH MD5=${CATCH2_HASH}
            SOURCE_DIR  ${CMAKE_CURRENT_BINARY_DIR}/catch2
    )
endif ()
unset(CATCH2_URL)
unset(CATCH2_HASH)
FetchContent_MakeAvailable(Catch2)
