cmake_minimum_required(VERSION 3.4)

project(AndroidNDK)
if (CMAKE_BUILD_TYPE MATCHES DEBUG)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION armeabi-v7a)
set(CMAKE_ANDROID_ARCH_ABI arm)

# Set so tell CMake to generate database .json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# List of explicit header directories
include_directories(
    src/include
)

add_subdirectory(src/template_module)

if (CMAKE_BUILD_TYPE MATCHES TEST)
    add_subdirectory(src/googletest)
endif()