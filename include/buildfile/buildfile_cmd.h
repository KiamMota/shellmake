#include "stdlib.h"

#ifndef _BUILDFILE_CMD_H_
#define _BUILDFILE_CMD_H_

#define BCMD_MINIMUM_VER_REQ "minimum_version_required"
#define BCMD_FILENAME "filename"
#define BCMD_REQUIRED_ROOT "required_root"
#define BCMD_DISTRO_ORIGINS "distro_origins"
#define BCMD_DISTRO_EXCLUDE "distro_exclude"
#define BCMD_SHELL_TARGETS  "shell_targets"

typedef struct
{
  char* cmd_minimum_version_required;
  char* cmd_filename;
  int cmd_required_root;
  /* arrays */
  char** cmd_distro_origins; long cmd_distro_origins_len;
  char** cmd_distro_targets; long cmd_distro_targets_len;
  char** cmd_distro_exclude; long cmd_distro_exclude_len;
  char** cmd_shell_targets;  long cmd_shell_targets_len;

} BUILD_CMD;

BUILD_CMD* bcmd_init();
void bcmd_destroy(BUILD_CMD** bcmd);
void bcmd_parse(BUILD_CMD* bcmd, char* buffer);

#endif
