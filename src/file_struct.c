#include <stdio.h>
#include <string.h>
#include "file/file_struct.h"

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

BOOL f_file_exists(char* name)
{
  FILE* eph_file = fopen(name, "r");
  if(!eph_file) return FALSE;
  else return TRUE;
}

BOOL f_openr_file(FILE_STRUCT* file_struct)
{
  file_struct->file_ptr = fopen(file_struct->file_name, "rb");
  if(!file_struct->file_ptr) return GENERIC_ERR;
  return TRUE;
}

BOOL f_close_file(FILE_STRUCT* file_struct)
{
  if(file_struct->file_ptr){
    fclose(file_struct->file_ptr);
    return TRUE;
  }
  return GENERIC_ERR;
}

BOOL f_start_buffer(FILE_STRUCT* fs, char** buffer)
{
  fseek(fs->file_ptr, 0, SEEK_END);
  
  fs->lenght = ftell(fs->file_ptr);
  
  rewind(fs->file_ptr);
  
  fs->buffer = malloc(fs->lenght + 1);
  
  fread(fs->buffer, 1, fs->lenght, fs->file_ptr);
  
  fs->buffer[fs->lenght] = '\0';
  
  *buffer = malloc(fs->lenght + 1);
  
  if(!*buffer) return FALSE;
  strcpy(*buffer, fs->buffer);
  return 1;
}

