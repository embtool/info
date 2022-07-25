cmake_minimum_required(VERSION 3.10)
project(info VERSION 1.0)

include(info.cmake)

add_custom_target(
  info_gen
  COMMAND
    ${CMAKE_COMMAND} "-DPROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}"
    "-DINFO_GIT_DIR=${INFO_GIT_DIR}" "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}" -P
    "${CMAKE_CURRENT_SOURCE_DIR}/info.cmake"
  COMMENT "Updating build information")

add_library(info include/info.h "${PROJECT_BINARY_DIR}/src/info.c")
add_dependencies(info info_gen)
target_include_directories(info PUBLIC include)
