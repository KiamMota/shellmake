cmake_minimum_required(VERSION 3.10)

project(shmake C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(FILEBUILD_SRC
    src/buildfile/buildfile_file.c
    src/buildfile/buildfile_cmd.c
    src/buildfile/buildfile_json_parse.c
)

set(SOURCES
    src/main.c
    src/file_struct.c
    src/string_validation.c
    src/io.c
    src/event.c
    src/env_var.c

    src/strvec.c

)

set(ALL_SRC
    ${SOURCES} ${FILEBUILD_SRC}
)

add_executable(shmake ${ALL_SRC})
add_subdirectory(external/cjson)
target_link_libraries(shmake PRIVATE cjson)

include_directories(include external/cjson)
