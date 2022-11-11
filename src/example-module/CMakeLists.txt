cmake_minimum_required(VERSION 3.16)

project(ExampleModule VERSION 0.0.0 LANGUAGES CXX)

# == BUILD ==

#find_package()

set(HEADER_FILES
        include/ExampleModule/ExampleModule.h)

set(SOURCE_FILES
        src/ExampleModule.cpp)

add_library(${PROJECT_NAME}
        ${HEADER_FILES}
        ${SOURCE_FILES})

add_library(${CMAKE_PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

#target_link_libraries(${PROJECT_NAME}
#        PRIVATE
#        PUBLIC)

target_compile_features(${PROJECT_NAME}
        PRIVATE
            cxx_std_17
        PUBLIC)

target_include_directories(${PROJECT_NAME}
        PUBLIC
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include/ExampleModule>
        PRIVATE
            src)

# == CONFIG ==

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(PROJECT_CONFIG_VERSION_FILE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Version.cmake")
set(PROJECT_CONFIG_FILE         "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake")

configure_package_config_file(cmake/config.cmake.in
        ${PROJECT_CONFIG_FILE}
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake)

write_basic_package_version_file(
        ${PROJECT_CONFIG_VERSION_FILE}
        COMPATIBILITY SameMajorVersion)

# == INSTALL ==

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${CMAKE_BUILD_TYPE}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/${CMAKE_BUILD_TYPE})

install(FILES ${HEADER_FILES}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ExampleModule)

install(FILES
            ${PROJECT_CONFIG_VERSION_FILE}
            ${PROJECT_CONFIG_FILE}
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${CMAKE_PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

# == EXPORT ==

export(EXPORT ${PROJECT_NAME}Targets
       FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake
       NAMESPACE ${CMAKE_PROJECT_NAME}::)

export(PACKAGE ${PROJECT_NAME})
