#include "buildfile/bf_cmd.h"

FILEBUILD_CMD* fbcmd_init()
{
  FILEBUILD_CMD* fb_cmd = malloc(sizeof(FILEBUILD_CMD));
  return fb_cmd;
}

void fbcmd_destroy(FILEBUILD_CMD** fb_cmd)
{
  if(fb_cmd && *fb_cmd)
  {
    free(*fb_cmd);
    *fb_cmd = NULL;
  }
}
