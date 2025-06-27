#include <stdio.h>
#include <stdlib.h>

#ifndef _SHF_STRUCT_
#define _SHF_STRUCT_

typedef struct 
{
  FILE* file_ptr;
  char* file_name;
  char* buffer;
  int current_line;
  long lenght;
} FILE_STRUCT;

FILE_STRUCT* f_init_file(char* file_name);
void         f_destroy_file(FILE_STRUCT** fs);
int          f_file_exists(char* name);
int          f_validate_and_start_buffer(FILE_STRUCT* fs, char* buffer);
int          f_openr_file(FILE_STRUCT* fs);
int          f_close_file(FILE_STRUCT* fs);

#endif
