#include "buildfile/bf_cmd.h"
#include "stdlib.h"
#include <string.h>

#ifndef _JSON_BUILD_H_
#define _JSON_BUILD_H_

typedef struct
{
  char*      buffer;
  BUILD_CMD* cmds;
} BUILDFILE;

BUILDFILE* bf_init(char* buffer);
void bf_destroy(BUILDFILE** bfile);


#endif
