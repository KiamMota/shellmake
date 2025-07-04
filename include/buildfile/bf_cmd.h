#include "stdlib.h"

#ifndef _BUILDFILE_CMD_H_
#define _BUILDFILE_CMD_H_

typedef struct
{
  char* cmd_minimum_version_required;
  char* cmd_filename;
  int cmd_required_root;
  /* arrays */
  char** cmd_distro_origins; long cmd_distro_origins_len;
  char** cmd_distro_targets;
  char** cmd_distro_exclude;
  char** cmd_shell_targets;

} BUILD_CMD;

BUILD_CMD* fbcmd_init();
void bf_parse(BUILD_CMD* build);
void bf_insert_cmds(BUILD_CMD* build);
void fbcmd_destroy(BUILD_CMD** fb_cmd);

#endif
