#include "stdlib.h"
#include "shellmake.h"
#include "strvec.h"

#ifndef _BUILDFILE_CMD_H_
#define _BUILDFILE_CMD_H_

/*==================================*/ 

// ==>  list of defines (commands can be changed)

#define BCMD_MINIMUM_VER_REQ "minimum_version_required"
#define BCMD_FILENAME "filename"
#define BCMD_REQUIRED_ROOT "required_root"
#define BCMD_DISTRO_ORIGINS "sa_distro_origins"
#define BCMD_DISTRO_TARGETS "sa_distro_targets"
#define BCMD_DISTRO_EXCLUDE "sa_distro_exclude"
#define BCMD_SHELL_TARGETS  "shell_targets"

/*==================================*/ 

// ==>  build_cmd its a struct that hold the build commands

typedef struct
{
// ==> 'sa' means 'string array'
  char* cmd_minimum_version_required;
  char* cmd_filename;
  BOOL cmd_required_root; 
  strvec_t* sa_distro_targets;
  strvec_t* sa_distro_origins;
  strvec_t* sa_distro_exclude;
  strvec_t* sa_shell_targets;
} BUILD_CMD;

BUILD_CMD* bcmd_alloc();
void bcmd_destroy(BUILD_CMD** bcmd);
void bcmd_json_parse(BUILD_CMD* bcmd, char* buffer);

#endif
