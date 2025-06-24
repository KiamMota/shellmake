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

FILE_STRUCT* f_init_file(char* file_name);
void         f_destroy_file(FILE_STRUCT** file_struct);
int          f_file_exists(char* file_string);
int          f_open_file(FILE_STRUCT* file_struct);
int          f_close_file(FILE_STRUCT* file_struct);

#endif
