#include "shared/file/file_struct.h"
#include "event_list.h"


#include "shared/strvec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE_STRUCT* fst_alloc(char* file_name)
{  
  FILE_STRUCT* fs= malloc(sizeof(FILE_STRUCT));
  

  f_remove_nl(file_name);
  fs->file_name = strdup(file_name);
  
  return fs;
}

void fst_destroy(FILE_STRUCT** fs)
{
  if(fs && *fs){
    free((*fs)->file_name);
    free((*fs)->buffer);
    free(*fs);
    *fs = NULL;
  }
}

BOOL fst_file_is_empty(char* file_name)
{	
	FILE* fs = fopen(file_name, "r");
	fseek(fs, 0, SEEK_END);
	long fsize = ftell(fs);
	if(fsize == 0 || fsize < 0) return TRUE;
	return FALSE;
}

BOOL fst_file_exists(char* name)
{
  FILE* eph_file = fopen(name, "r");
  if(!eph_file) return FALSE;
  else return TRUE;
}

BOOL fst_openr(FILE_STRUCT* file_struct)
{
  file_struct->file_ptr = fopen(file_struct->file_name, "rb");
  if(!file_struct->file_ptr) return GENERIC_ERR;
  return TRUE;
}

BOOL fst_close(FILE_STRUCT* file_struct)
{
  if(file_struct->file_ptr){
    fclose(file_struct->file_ptr);
	return TRUE;
  }
  return GENERIC_ERR;
}

BOOL fst_start_buffer(FILE_STRUCT* fs)
{
  fseek(fs->file_ptr, 0, SEEK_END);
  fs->lenght = ftell(fs->file_ptr);
  rewind(fs->file_ptr);
  fs->buffer = malloc(fs->lenght + 1);
  fread(fs->buffer, 1, fs->lenght, fs->file_ptr);
  fs->buffer[fs->lenght] = '\0';
  return 1;
}

char* fst_get_fstbuff(FILE_STRUCT* fs)
{
		return fs->buffer;
}
