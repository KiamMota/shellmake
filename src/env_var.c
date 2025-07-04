#include "env_var.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ENV_VARS* alloc_envvars()
{
  ENV_VARS* evars = malloc(sizeof(ENV_VARS));
  return evars;
}

BOOL env_get_distro(ENV_VARS* evar) {
  char* eph_buffer = malloc(256);
  char* eph_start = eph_buffer;
  FILE *fp = popen("cat /etc/os-release | grep '^ID='", "r");
  if (fgets(eph_buffer, 256, fp) == NULL)
  {
    return GENERIC_ERR;
  }
    evar->DISTRO = malloc(strlen(eph_start) + 1);
    char* idpos = strstr(eph_buffer, "ID=");
    if(idpos) eph_start = idpos + strlen("ID=");
    eph_start[strcspn(eph_buffer, "\n")] = '\0';
  
    strcpy(evar->DISTRO, eph_start);

  pclose(fp);
  free(eph_buffer);
  return TRUE;
}

BOOL env_get_username(ENV_VARS* evar)
{
  char* cmd = "whoami";
  char* eph_result = malloc(256);
  FILE* fp = popen(cmd, "r");
  if(fgets(eph_result, 256, fp) == NULL) return GENERIC_ERR;
  evar->USERNAME = malloc(strlen(eph_result));
  strcpy(evar->USERNAME, eph_result);
  return TRUE;
}

BOOL env_get_hostname(ENV_VARS* evar)
{
  char* cmd = "hostname";
  char* eph_result = malloc(256);
  FILE* fp = popen(cmd, "r");
  if(fgets(eph_result, 256, fp) == NULL) return TRUE;
  
  evar->HOSTNAME = malloc(strlen(eph_result));
  strcpy(evar->HOSTNAME, eph_result);
  return TRUE;
}

BOOL env_get_arch(ENV_VARS* evar)
{
 /*todo*/ 
}
