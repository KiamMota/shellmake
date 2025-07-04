cmake_minimum_required(VERSION 3.10)

project(shmake C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set
(
    FILEBUILD_SRC
    src/buildfile/bf_file.c
    src/buildfile/bf_cmd.c
    src/buildfile/bf_parse.c
)

set
(
    SOURCES
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

include_directories
(
    include
    external/cjson
)
