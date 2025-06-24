#include <stdio.h>
#include <stdlib.h>

#ifndef _SHF_STRUCT_
#define _SHF_STRUCT_

typedef struct 
{
  FILE* file_ptr;
  char* file_name;
  char* file_string[255];
  int current_line;
  int size;
} FILE_STRUCT;

FILE_STRUCT* init_file(char* file_name);
void destroy_filestruct(FILE_STRUCT** file_struct);

void open_file(FILE_STRUCT* file_struct);

#endif
