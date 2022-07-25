# [Info - Build Information](https://github.com/embtool/info)

by [Djones A. Boni](https://github.com/djboni)

Add build information to a CMake project.

If you are using CMake, you can easily add build information to
your project.

The following information will be available as variables:

- Git commit describe: `TAG-N-gAAAAAAA-dirty`
- Git commit hash: `AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA-dirty`
- Build type: `Release`/`Debug`/...
- Build user and host: `john@workstation`
- Build date: `2022-12-31 23:59:59 +0000`
- Build time: `1672491599`

Here is an usage example, followed by its output:

```cpp
/* main.c */
#include "info.h"
#include <stdio.h>

void print_json_build_info(void)
{
    printf("{\n");
    printf("  \"git_commit_describe\": \"%s\",\n", git_commit_describe);
    printf("  \"git_commit_hash\": \"%s\",\n", git_commit_hash);
    printf("  \"build_type\": \"%s\",\n", build_type);
    printf("  \"build_user\": \"%s\",\n", build_user);
    printf("  \"build_date\": \"%s\",\n", build_date);
    printf("  \"build_time\": %lu\n", build_time);
    printf("}\n");
}

int main(void)
{
    print_json_build_info();

    return 0;
}
```

Output:

```json
{
  "git_commit_describe": "AAAAAAA-dirty",
  "git_commit_hash": "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA-dirty",
  "build_type": "Debug",
  "build_user": "user@host",
  "build_date": "2022-12-31 23:59:59 +0000",
  "build_time": 1672491599
}
```

## Using: add_subdirectory()

Copy this repository in your project, add the subdirectory, then link
to your executable or library. You can also set the Git directory where
to get the commit.

```console
$ git clone https://github.com/embtool/info
```

```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(info_test_add_submodule VERSION 1.0)

# Set Git directory (optional)
set(INFO_GIT_DIR "${PROJECT_SOURCE_DIR}")

# Add Info's subdirectory
add_subdirectory(info)

# Link Info to an executable or library
add_executable(main main.c)
target_link_libraries(main PRIVATE info)
```

## Using: External Project

Configure this repository as an external project, then link
to your executable or library. You can also set the Git directory where
to get the commit.

```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(info_test_add_submodule VERSION 1.0)

# Set Git directory (optional)
set(INFO_GIT_DIR "${PROJECT_SOURCE_DIR}")

# Add Info as an external project
include(FetchContent)
FetchContent_Declare(
  info
  GIT_REPOSITORY https://github.com/embtool/info
  GIT_TAG main # or use a tag, eg. v1.0
)
FetchContent_MakeAvailable(info)

# Link Info to an executable or library
add_executable(main main.c)
target_link_libraries(main PRIVATE info)
```
