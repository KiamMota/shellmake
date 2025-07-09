#include "buildfile/bfile.h"
#include <time.h>

BUILDFILE* bf_init(char* file_name)
{
  BUILDFILE* bfile = malloc(sizeof(BUILDFILE));
  bfile->bfile = f_init_file(file_name);
  bfile->bcmd = bcmd_alloc();  
  return bfile;
}

void bf_destroy(BUILDFILE** bfile)
{

if(bfile && *bfile)
{
    f_close_file((*bfile)->bfile);
		bcmd_destroy(&(*bfile)->bcmd);
		free(*bfile);
		*bfile = NULL;
}

}

