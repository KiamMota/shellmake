#include <stdio.h>
#include <string.h>
#include "file/shfile.h"

FILE_STRUCT* f_init_file(char* file_name)
{  
  FILE_STRUCT* fs_factory = malloc(sizeof(FILE_STRUCT));
  fs_factory->file_name = file_name;
  fs_factory->current_line = 0;
  return fs_factory;
}

void f_destroy_file(FILE_STRUCT** fs)
{
  free(*fs);
  *fs = NULL;
}

int f_file_exists(char* file_exists)
{
  FILE* eph_file = fopen(file_exists, "r");
  if(!eph_file) return 0;
  fclose(eph_file);
  return 1;
}

void f_buffer_init(FILE_STRUCT* fs)
{
  fseek(fs->file_ptr, 0, SEEK_END);
  fs->lenght = ftell(fs->file_ptr);
  rewind(fs->file_ptr);
  fs->buffer = malloc(fs->lenght + 1);
  fread(fs->buffer, 1, fs->lenght, fs->file_ptr);
  fs->buffer[fs->lenght] = '\0';
}

int f_openr_file(FILE_STRUCT* file_struct)
{
  file_struct->file_ptr = fopen(file_struct->file_name, "rb");
  if(!file_struct->file_ptr) return -1;
  return 1;
}

int f_openw_file(FILE_STRUCT* fs)
{
  fs->file_ptr = fopen(fs->file_name, "a");
  if(!fs->file_ptr) return -1;
  return 1;
}

int f_close_file(FILE_STRUCT* file_struct)
{
  if(file_struct->file_ptr){
    fclose(file_struct->file_ptr);
    return 1;
  }
  return -1;
}

