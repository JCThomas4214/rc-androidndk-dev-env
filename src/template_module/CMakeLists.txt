cmake_minimum_required(VERSION 3.4)

project(templateProject)

#set per module
set(MODULE_FLAGS            "-DTEMPLATEMODULE -DTEMPLATEPROJECT")

#common flags for each build type, shouldn't need to change
set(COMMON_FLAGS            "${MODULE_FLAGS} -std=gnu99 -Wall -Wuninitialized")
set(COMMON_FLAGS_DEBUG      "${COMMON_FLAGS} -O0 -g -ggdb -fPIE -funwind-tables -Wfatal-errors -Werror -fno-omit-frame-pointer")
set(COMMON_FLAGS_RELEASE    "${COMMON_FLAGS} -Os -s -ffunction-sections -fdata-sections -fvisibility=hidden -fmerge-all-constants -Wno-builtin-macro-redefined -Wextra")

#compiler flags for building debug
set(CMAKE_C_FLAGS_DEBUG     "${COMMON_FLAGS_DEBUG} -DDEBUG -DDebug -DDEBUG_ON -DSTANDALONE_BUILD")
set(CMAKE_CXX_FLAGS_DEBUG   "${COMMON_FLAGS_DEBUG} -std=c++11 -DDEBUG -DDebug -DDEBUG_ON -DSTANDALONE_BUILD")

#compiler flags for building release
set(CMAKE_C_FLAGS_RELEASE   "${COMMON_FLAGS_RELEASE} -DSTANDALONE_BUILD")
set(CMAKE_CXX_FLAGS_RELEASE "${COMMON_FLAGS_RELEASE} -std=c++11 -DSTANDALONE_BUILD")

# Set our Test flags
set(CMAKE_C_FLAGS_TEST      "${COMMON_FLAGS_DEBUG} -DTEST -DSTANDALONE_BUILD -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_TEST    "${COMMON_FLAGS_DEBUG} -std=c++11 -DTEST -DSTANDALONE_BUILD -fno-omit-frame-pointer")


set(SDK_STANDALONE_SOURCES
    
)

set(PACKAGE_SOURCES

)

if (NOT CMAKE_BUILD_TYPE MATCHES TEST)

    add_executable(template_module_bin template_module.c ${PACKAGE_SOURCES} ${SDK_STANDALONE_SOURCES})

    target_include_directories(
        template_module_bin PUBLIC
        ../include
    )

    target_link_libraries(template_module_bin)   

else()

    set(UNIT_TEST_FILES
        template_module_utest.cpp
    )

    add_executable(template_module_test template_module.c ${UNIT_TEST_FILES} ${PACKAGE_SOURCES} ${SDK_STANDALONE_SOURCES})

    target_include_directories(
        template_module_test PUBLIC
        ../include
    )

    target_link_libraries(template_module_test gmock gmock_main)
    enable_testing()

endif()