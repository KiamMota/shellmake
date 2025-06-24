#include <stdio.h>
#include <stdlib.h>

#ifndef _SHF_STRUCT_
#define _SHF_STRUCT_

struct file_struct
{
  FILE* file_ptr;
  char* file_name;
  char* file_string[255];
  int current_line;
  int size;
};

struct file_struct* init_file(char* file_name);
void destroy_filestruct(struct file_struct** file_struct);

void file_content_tostr(struct file_struct* file, char* buffer);

#endif
