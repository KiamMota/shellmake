#include <stdlib.h>
#include "buildfile/cmd.h"

BUILD_CMD* bcmd_alloc()
{
  BUILD_CMD* fb_cmd = malloc(sizeof(BUILD_CMD));
  strvec_alloc(fb_cmd->sa_distro_exclude);
  strvec_alloc(fb_cmd->sa_distro_origins);
  strvec_alloc(fb_cmd->sa_distro_targets);
  strvec_alloc(fb_cmd->sa_shell_targets);

  return fb_cmd;
}

void bcmd_destroy(BUILD_CMD** bcmd)
{
  if(bcmd && *bcmd)
  {
	strvec_destroy(&(*bcmd)->sa_shell_targets);
	strvec_destroy(&(*bcmd)->sa_distro_targets);
	strvec_destroy(&(*bcmd)->sa_distro_exclude);
	strvec_destroy(&(*bcmd)->sa_distro_origins);
	free(*bcmd);
	*bcmd = NULL;
  } 
}
