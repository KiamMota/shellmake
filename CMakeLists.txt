cmake_minimum_required(VERSION 3.10)

project(shmake C)

set(SOURCES
    src/main.c
    src/shfile.c
    src/string_validation.c
    src/parser.c
    src/io.c
    src/event.c
)

add_executable(shmake ${SOURCES})

target_include_directories(shmake PUBLIC include)
