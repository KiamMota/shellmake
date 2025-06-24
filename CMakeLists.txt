cmake_minimum_required(VERSION 3.10)

project(shmake)

set(SOURCES
    main.c
    shfile.c
    string_validation.c
    parser.c
)

add_executable(shmake ${SOURCES})

target_include_directories(shmake PUBLIC include)
