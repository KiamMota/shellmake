cmake_minimum_required(VERSION 3.10)

project(shellmake C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SHARED
		src/shared/strvec.c
		src/shared/file/file_struct.c
		src/shared/file/string_validation.c
)
set(PIPELINE
		src/pipeline/init_argv.c
)

set(FILEBUILD_SRC
    src/buildfile/bfile.c
    src/buildfile/cmd.c
    src/buildfile/json_parse.c
)

set(SOURCES
    src/main.c
    src/env_var.c
    src/event_list.c

)

set(ALL_SRC
    ${SOURCES} ${FILEBUILD_SRC}
	${PIPELINE} ${SHARED}
)



add_executable(shellmake ${ALL_SRC})
add_subdirectory(external/cjson)
target_link_libraries(shellmake PRIVATE cjson)

include_directories(include external/cjson)
