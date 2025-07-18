#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared/strvec.h"

#include "shared/shellmake.h"
#include "shared/file/string_validation.h"

#ifndef _SHF_STRUCT_
#define _SHF_STRUCT_

typedef struct 
{
  FILE* file_ptr;
  char* file_name;
  char* buffer;
  long lenght;
} FILE_STRUCT;

FILE_STRUCT*  fst_alloc(char* file_name);
void          fst_destroy(FILE_STRUCT** fs);
BOOL          fst_file_exists(char* name);
BOOL          fst_start_buffer(FILE_STRUCT* fs);
BOOL          fst_openr(FILE_STRUCT* fs);
BOOL          fst_close(FILE_STRUCT* fs);
char*         fst_get_fstbuff(FILE_STRUCT* fs);

#endif
