#include "buildfile/buildfile_cmd.h"



BUILD_CMD* bcmd_init()
{
  BUILD_CMD* fb_cmd = malloc(sizeof(BUILD_CMD));
  return fb_cmd;
}

void bcmd_destroy(BUILD_CMD** bcmd)
{
  if(bcmd && *bcmd) free(*bcmd); *bcmd = NULL;
}
