#include "stdlib.h"

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
  int*  SUPER_USER;
  char* HOSTNAME;
  ARCHTECTURE* ARCH;
}ENV_VARS;

ENV_VARS* get_distro();
ENV_VARS* get_username();
ENV_VARS* get_superuser();
ENV_VARS* get_hostname();
ENV_VARS* get_arch();

#endif
