#include "buildfile/bf_cmd.h"
#include "stdlib.h"

#ifndef _JSON_BUILD_H_
#define _JSON_BUILD_H_

typedef struct
{
  char*       buffer;
  FILEBUILD_CMD* cmds;
} BUILDFILE;

BUILDFILE* bf_init(char* buffer);
void bf_destroy(BUILDFILE** bfile);
void bf_parse(BUILDFILE* build);
void bf_insert_cmds(BUILDFILE* build);


#endif
