#include "buildfile/buildfile_cmd.h"
#include <stdlib.h>

BUILD_CMD* bcmd_alloc()
{
  BUILD_CMD* fb_cmd = malloc(sizeof(BUILD_CMD));
  strarr_alloc(fb_cmd->sa_distro_exclude);
  strarr_alloc(fb_cmd->sa_distro_origins);
  strarr_alloc(fb_cmd->sa_distro_targets);
  strarr_alloc(fb_cmd->sa_shell_targets);

  return fb_cmd;
}

void bcmd_destroy(BUILD_CMD** bcmd)
{
  if(bcmd && *bcmd)
  {
	strarr_destroy(&(*bcmd)->sa_shell_targets);
	strarr_destroy(&(*bcmd)->sa_distro_targets);
	strarr_destroy(&(*bcmd)->sa_distro_exclude);
	strarr_destroy(&(*bcmd)->sa_distro_origins);

	free(*bcmd);
	*bcmd = NULL;
  } 
}
