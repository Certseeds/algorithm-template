cmake_minimum_required(VERSION 3.16.6)
project(CS203_CATCH2_LIB)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set("BUILD_${LIB_WAY}_LIBS" YES)

include(FetchContent)
CMAKE_CMP_0135()

set(CATCH2_HASH "c2fef0ffbe8af6b20e86f8d0e79b6aac")
set(CATCH2_LOCAL_TAR ${CMAKE_CURRENT_SOURCE_DIR}/catch2.tar.gz)

message(STATUS "Using local Catch2 tarball: ${CATCH2_LOCAL_TAR}")

# 现在只使用 file:// 协议让 FetchContent 从本地 archive 加载
get_filename_component(_abs_tar ${CATCH2_LOCAL_TAR} ABSOLUTE)
file(TO_CMAKE_PATH ${_abs_tar} _tar_unix) # 在 Windows 上转换路径分隔
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    FetchContent_Declare(
            Catch2
            URL file://${_tar_unix}
            URL_HASH MD5=${CATCH2_HASH}
            SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch2
    )
else ()
    FetchContent_Declare(
            Catch2
            URL file://${_tar_unix}
            URL_HASH MD5=${CATCH2_HASH}
            SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/catch2
    )
endif ()

FetchContent_MakeAvailable(Catch2)
unset(CATCH2_HASH)
unset(CATCH2_LOCAL_TAR)
unset(_abs_str)
unset(_tar_unix)
