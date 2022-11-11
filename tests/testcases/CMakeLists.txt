cmake_minimum_required(VERSION 3.16)

project(testcases)

add_executable(${PROJECT_NAME}
        src/TestExample.cpp)

target_link_libraries(${PROJECT_NAME}
        gtest
        gtest_main
        ExampleModule)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
