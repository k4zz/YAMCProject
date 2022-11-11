cmake_minimum_required(VERSION 3.16)

project(YAMCProject
        VERSION 0.0)

option(TESTS "" OFF)

add_subdirectory(src/example-module)
add_subdirectory(src/executable)

if (${TESTS})
    add_subdirectory(3rdparty/googletest)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif ()
