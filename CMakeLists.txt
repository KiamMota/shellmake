cmake_minimum_required(VERSION 3.10)

project(shmake C)

set(FILEBUILD_SRC
    src/buildfile/bf_file.c
    src/buildfile/bf_cmd.c
)

set(SOURCES
    src/main.c
    src/shfile.c
    src/string_validation.c
    src/parser.c
    src/io.c
    src/event.c
    src/parser_pipe.c
    src/env_var.c
)

set(ALL_SRC
    ${SOURCES} ${FILEBUILD_SRC}
)

add_executable(shmake ${ALL_SRC})

target_include_directories(shmake PUBLIC include)
