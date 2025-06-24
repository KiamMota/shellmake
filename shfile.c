#include <cstdio>
#include <stdio.h>
#include "shfile.h"

struct file_struct* init_file(char* file_name)
{  
  struct file_struct* fs_factory;
  fs_factory->file_name = file_name;
  fs_factory->current_line = 0;
  fs_factory->file_ptr = fopen(fs_factory->file_name, "a");
  fseek(fs_factory->file_ptr, 0, SEEK_END);
  fs_factory->size = ftell(fs_factory->file_ptr);
  fseek(fs_factory->file_ptr, 0, SEEK_SET);
  return fs_factory;
}

void destroy_filestruct(struct file_struct** file_struct)
{
  if(*file_struct)
  {
    if((*file_struct)->file_ptr) 
      fclose((*file_struct)->file_ptr);
    free(*file_struct);
    *file_struct = NULL;
  }
}

void file_content_tostr(struct file_struct* struct_file, char* buffer)
{
  buffer = (char*)malloc(struct_file->size);
   

  
}
