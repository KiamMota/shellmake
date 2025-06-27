#include <stdio.h>
#include <string.h>
#include "file/shfile.h"

void _buffer_init(FILE_STRUCT* fs);

FILE_STRUCT* f_init_file(char* file_name)
{  
  FILE_STRUCT* fs= malloc(sizeof(FILE_STRUCT));
  fs->file_name = strdup(file_name);
  fs->current_line = 0;
  return fs;
}

void f_destroy_file(FILE_STRUCT** fs)
{
  if(*fs) free(*fs);
  fs = NULL;
}

int f_file_exists(char* name)
{
  FILE* eph_file = fopen(name, "r");
  if(!eph_file) return 0;
  else return 1;
}

int f_openr_file(FILE_STRUCT* file_struct)
{
  file_struct->file_ptr = fopen(file_struct->file_name, "rb");
  if(!file_struct->file_ptr) return -1;
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

int f_validate_and_start_buffer(FILE_STRUCT* fs, char* buffer)
{
  if(!f_file_exists(fs->file_name)) return -1;
  _buffer_init(fs);
  buffer = (char*)malloc(sizeof(fs->buffer));
  strcpy(buffer, fs->buffer);
  return 1;
}

void _buffer_init(FILE_STRUCT* fs)
{
  fseek(fs->file_ptr, 0, SEEK_END);
  fs->lenght = ftell(fs->file_ptr);
  rewind(fs->file_ptr);
  fs->buffer = malloc(fs->lenght + 1);
  fread(fs->buffer, 1, fs->lenght, fs->file_ptr);
  fs->buffer[fs->lenght] = '\0';
}
