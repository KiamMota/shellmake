#include <stdio.h>
#include "shfile.h"

FILE_STRUCT* init_file(char* file_name)
{  
  FILE_STRUCT* fs_factory;
  fs_factory->file_name = file_name;
  fs_factory->current_line = 0;
  fs_factory->file_ptr = fopen(fs_factory->file_name, "a");
  fseek(fs_factory->file_ptr, 0, SEEK_END);
  fs_factory->size = ftell(fs_factory->file_ptr);
  fseek(fs_factory->file_ptr, 0, SEEK_SET);
  return fs_factory;
}

void destroy_filestruct(FILE_STRUCT** file_struct)
{
  if(*file_struct)
  {
    if((*file_struct)->file_ptr) 
      fclose((*file_struct)->file_ptr);
    free(*file_struct);
    *file_struct = NULL;
  }
}

int open_file(FILE_STRUCT* file_struct)
{
  file_struct->file_ptr = fopen(file_struct->file_name, "a");
  if(!file_struct->file_ptr) return -1;
  return 1;
}

int close_file(FILE_STRUCT* file_struct)
{
  if(file_struct->file_ptr){
    fclose(file_struct->file_ptr);
    return 1;
  }
  return -1;
}
