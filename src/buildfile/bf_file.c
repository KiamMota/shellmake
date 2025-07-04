#include "buildfile/file_struct.h"

BUILDFILE* bf_init(char* buffer)
{
  BUILDFILE* build_file = malloc(sizeof(BUILDFILE));
  build_file->buffer = malloc(strlen(buffer) + 1);
  return build_file;
}

void bf_destroy(BUILDFILE** bfile)
{
  if(bfile && *bfile)
  {
    free((*bfile)->buffer);
    free((*bfile)->cmds);
    free(*bfile);
    *bfile = NULL;    
  }
  return;
}

