#include "string_validation.h"
#include <stddef.h>

int validate_shf_suffix(char *file_context)
{
  char* pos = strstr(file_context, ".sh");
  if(pos != NULL) return 1;
  return 0;
}

void remove_nl(char *shf_string)
{
  char* pos = strchr(shf_string, '\n');
  if(pos) *pos = '\0';
  else return;
}
