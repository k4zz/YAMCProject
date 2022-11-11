cmake_minimum_required(VERSION 3.16)

project(${CMAKE_PROJECT_NAME} VERSION 0.0.0 LANGUAGES CXX)

# == BUILD ==

# find_package()

set(SOURCE_FILES
        src/main.cpp)

add_executable(${PROJECT_NAME}
        ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        PRIVATE
            YAMCProject::ExampleModule
        PUBLIC)

target_compile_features(${PROJECT_NAME}
        PRIVATE
            cxx_std_17)

target_include_directories(${PROJECT_NAME}
        PRIVATE
            src)

# == INSTALL ==

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
