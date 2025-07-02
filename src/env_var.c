#include "env_var.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _set_distro(char** buffer);

ENV_VARS *get_distro() {
  char* eph_buffer = malloc(256);
  char* eph_start = eph_buffer;
  ENV_VARS *ev_distro = malloc(sizeof(ENV_VARS));
  FILE *fp = popen("cat /etc/os-release | grep '^ID='", "r");
  if (fgets(eph_buffer, 256, fp) == NULL)
  {
    /* foo */
    return ev_distro;
  }
    ev_distro->DISTRO = malloc(strlen(eph_start) + 1);
    char* idpos = strstr(eph_buffer, "ID=");
    if(idpos) eph_start = idpos + strlen("ID=");
    eph_start[strcspn(eph_buffer, "\n")] = '\0';
    _set_distro(&eph_start);
  
    strcpy(ev_distro->DISTRO, eph_start);

  pclose(fp);
  free(eph_buffer);
  return ev_distro;
}


void _set_distro(char** buffer)
{
  if(!strcmp(*buffer, "linuxmint"))
  {
    strcpy(*buffer, "ubinto");
  }
}
