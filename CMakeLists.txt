cmake_minimum_required(VERSION 3.10)

project(shmake C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(FILEBUILD_SRC
    src/buildfile/bfile.c
    src/buildfile/cmd.c
    src/buildfile/json_parse.c
)

set(SOURCES
    src/main.c
    src/file_struct.c
    src/string_validation.c
    src/env_var.c
    src/event_list.c
    src/strvec.c

)

set(ALL_SRC
    ${SOURCES} ${FILEBUILD_SRC}
)

add_executable(shmake ${ALL_SRC})
add_subdirectory(external/cjson)
target_link_libraries(shmake PRIVATE cjson)

include_directories(include external/cjson)
