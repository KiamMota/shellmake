#include "stdlib.h"
#include "shared/shellmake.h"

#ifndef _ENV_VARHS_H_
#define _ENV_VARHS_H_

typedef enum
{
  X86_64,
  I386, 
  I686,
  ARMV7L,
  AARCH64,
  RISCV64,
  PPC64LE,
  S390X
}ARCHTECTURE;

typedef struct
{
  char* DISTRO;
  char* USERNAME;
  char* HOSTNAME;
  ARCHTECTURE* ARCH;
}ENV_VARS;

ENV_VARS* alloc_envvars();
void      destroy_envvars(ENV_VARS** evar);
BOOL env_get_distro(ENV_VARS* evar);
BOOL env_get_username(ENV_VARS* evar);
BOOL env_get_hostname(ENV_VARS* evar);
BOOL env_get_arch(ENV_VARS* evar);

#endif
