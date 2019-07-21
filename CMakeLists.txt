cmake_minimum_required(VERSION 3.4)

project(AndroidNDK)
#set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION armeabi-v7a)
set(CMAKE_ANDROID_ARCH_ABI arm)

# Set our compiler standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Set our NDK variables
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fPIE")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexceptions -frtti -fPIE")

# Set debug
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCMAKE_BUILD_TYPE=Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCMAKE_BUILD_TYPE=Debug")

add_subdirectory(src)