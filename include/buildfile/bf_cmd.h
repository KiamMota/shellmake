#include "stdlib.h"

#ifndef _BUILDFILE_CMD_H_
#define _BUILDFILE_CMD_H_

typedef struct
{
  char* cmd_minimum_version_required;
  char* cmd_distro_origins;
  char* cmd_distro_targets;
  char* cmd_distro_exclude;
  char* cmd_filename;
  char* cmd_shell_targets;
  char* cmd_required_root;
} FILEBUILD_CMD;

FILEBUILD_CMD* fbcmd_init();
void fbcmd_destroy(FILEBUILD_CMD** fb_cmd);

#endif
