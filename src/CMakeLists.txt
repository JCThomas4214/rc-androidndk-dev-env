set(SOURCES
    main.c
    TestCode.c
)
set(HEADERS
    TestCode.h
)

#add_executable(main ${SOURCES})
#target_link_libraries(main)

add_subdirectory(googletest)
add_subdirectory(tests)

enable_testing()