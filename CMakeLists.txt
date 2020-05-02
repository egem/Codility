project(Project-Template-C++)
cmake_minimum_required(VERSION 3.0)

include(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cmake-files)

AddAllSubdirsAsModule(${CMAKE_CURRENT_SOURCE_DIR}/app/modules)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

