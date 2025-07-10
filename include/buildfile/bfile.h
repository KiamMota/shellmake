// ==> this file represents the build file and the build commands

#include "buildfile/cmd.h"
#include "file/file_struct.h"
#include "file/string_validation.h"
#include "stdlib.h"
#include <string.h>

#ifndef _JSON_BUILD_H_
#define _JSON_BUILD_H_

// ==> this structs represents the build file itself
// the parser will call this structs when it find the shellmake 
// extends build directive

typedef struct
{
  FILE_STRUCT* bfile;
  BUILD_CMD* bcmd;
} BUILDFILE;

BUILDFILE* bf_init(char* file_name);
void bf_destroy(BUILDFILE** bfile);
void bf_init_parsing(BUILDFILE* bfile);

#endif
