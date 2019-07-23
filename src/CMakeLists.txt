project(srcProject)

# Set our Release flags
set(CMAKE_C_FLAGS_RELEASE "-std=gnu99 -Os -Wall -fPIE")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -Os -Wall -fexceptions -frtti -fPIE")
# Set our Debug flags
set(CMAKE_C_FLAGS_DEBUG "-std=gnu99 -O0 -g -ggdb -Wall -fPIE")
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -O0 -g -ggdb -Wall -fexceptions -frtti -fPIE")
# Set our Test flags
set(CMAKE_C_FLAGS_TEST "-std=gnu99 -O3 -g -ggdb -Wall -fPIE")
set(CMAKE_CXX_FLAGS_TEST "-std=c++11 -O3 -g -ggdb -Wall -fexceptions -frtti -fPIE")

if (NOT CMAKE_BUILD_TYPE MATCHES TEST)
    set(SOURCES
        main.c
        TestCode.c
    )
    set(HEADERS
        TestCode.h
    )

    add_executable(main ${SOURCES})
    target_link_libraries(main)
else()
    add_subdirectory(googletest)
    add_subdirectory(tests)

    enable_testing()
endif()