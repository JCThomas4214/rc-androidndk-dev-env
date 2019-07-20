set(TEST_SOURCES
    main.cpp
    testcases.cpp
    ../TestCode.c
)
set(TEST_HEADERS
    ../TestCode.h
)

add_executable(main ${TEST_SOURCES})
target_link_libraries(main
    gmock_main
)