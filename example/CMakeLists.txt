cmake_minimum_required(VERSION 3.10)
project(info_example VERSION 1.0)

# Set Git directory (optional)
set(INFO_GIT_DIR "${PROJECT_SOURCE_DIR}")

# Add Info as an external project
#
# ~~~
# include(FetchContent)
# FetchContent_Declare(
#   info
#   GIT_REPOSITORY https://github.com/embtool/info
#   GIT_TAG main # or use a tag, eg. v1.0
# )
# FetchContent_MakeAvailable(info)
# ~~~

# For this example we add Info as a subdirectory
add_subdirectory(.. info)

# Link Info to an executable or library
add_executable(main main.c)
target_link_libraries(main PRIVATE info)
