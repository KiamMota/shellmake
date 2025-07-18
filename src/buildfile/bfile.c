#include "buildfile/bfile.h"

BUILDFILE* bf_init(char* file_name)
{
  BUILDFILE* bfile = malloc(sizeof(BUILDFILE));
  bfile->bfile = fst_alloc(file_name);
  bfile->bcmd = bcmd_alloc();  
  return bfile;
}

void bf_destroy(BUILDFILE** bfile)
{
if(!bfile && !*bfile) return;

		fst_close((*bfile)->bfile);
		bcmd_destroy(&(*bfile)->bcmd);
		free(*bfile);
		*bfile = NULL;
}

void bf_init_parsing(BUILDFILE *bfile)
{
		if(!fst_file_exists(bfile->bfile->file_name))
		{
				printf("the file %s doesn't exists!", bfile->bfile->file_name);
				return;
		}
		fst_openr(bfile->bfile);
		fst_start_buffer(bfile->bfile);
		bcmd_json_parse(bfile->bcmd, bfile->bfile->buffer);				
}
