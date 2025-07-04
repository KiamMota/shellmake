#include <stdio.h>
#include <stdlib.h>
#include "shellmake.h"

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
BOOL          f_file_exists(char* name);
BOOL          f_start_buffer(FILE_STRUCT* fs, char** buffer);
BOOL          f_openr_file(FILE_STRUCT* fs);
BOOL          f_close_file(FILE_STRUCT* fs);

#endif
