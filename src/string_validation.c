#include "file/string_validation.h"
#include <stddef.h>

int f_validate_suffix(char *file_context, char* suffix)
{
  char* pos = strstr(file_context, suffix);
  if(pos != NULL) return 1;
  return 0;
}

void f_remove_nl(char *sh)
{
  char* pos = strchr(sh, '\n');
  if(pos) *pos = '\0';
  else return;
}
