#include "file/file_struct.h"
#include "event_list.h"

FILE_STRUCT* f_init_file(char* file_name)
{  
  FILE_STRUCT* fs= malloc(sizeof(FILE_STRUCT));
  

  f_remove_nl(file_name);
  fs->file_name = strdup(file_name);
  
  evlist_add(GLOBAL_EVLIST, SHMEV_GL_ALLOC);
  return fs;
}

void f_destroy_file(FILE_STRUCT** fs)
{
  if(fs && *fs){
    free((*fs)->file_name);
    evlist_add(GLOBAL_EVLIST, SHMEV_GL_DEALLOC);
    free((*fs)->buffer);
    evlist_add(GLOBAL_EVLIST, SHMEV_GL_DEALLOC);
    free(*fs);
    evlist_add(GLOBAL_EVLIST, SHMEV_GL_DEALLOC);
    *fs = NULL;
  }
}

BOOL f_file_exists(char* name)
{
  FILE* eph_file = fopen(name, "r");
  evlist_add(GLOBAL_EVLIST, SHMEV_FL_OPEN);
  if(!eph_file) return FALSE;
  else return TRUE;
}

BOOL f_openr_file(FILE_STRUCT* file_struct)
{
  file_struct->file_ptr = fopen(file_struct->file_name, "rb");
  evlist_add(GLOBAL_EVLIST, SHMEV_FL_OPEN);
  evlist_add(GLOBAL_EVLIST, SHMEV_FL_READ);

  if(!file_struct->file_ptr) return GENERIC_ERR;
  return TRUE;
}

BOOL f_close_file(FILE_STRUCT* file_struct)
{
  if(file_struct->file_ptr){
    fclose(file_struct->file_ptr);
    evlist_add(GLOBAL_EVLIST, SHMEV_FL_CLOSE);
	return TRUE;
  }
  return GENERIC_ERR;
}

BOOL f_start_buffer(FILE_STRUCT* fs)
{
  fseek(fs->file_ptr, 0, SEEK_END);
  fs->lenght = ftell(fs->file_ptr);
  rewind(fs->file_ptr);
  fs->buffer = malloc(fs->lenght + 1);
  fread(fs->buffer, 1, fs->lenght, fs->file_ptr);
  fs->buffer[fs->lenght] = '\0';
  return 1;
}

char* f_get_fs_buffer(FILE_STRUCT* fs)
{
		return fs->buffer;
}
