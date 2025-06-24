#include <stdio.h>
#include "file/shfile.h"
#include "file/string_validation.h"

int main(int argn, char* args[])
{
  
  char file_name[1024];
  char* file_buffer;

  printf("file to read: ");
  /* string_validate pipeline*/
  
  fgets(file_name, sizeof(file_name), stdin);
  
  validate_shf_suffix(file_name);
  remove_nl(file_name);  
  FILE_STRUCT* file = f_init_file(file_name);
  if(f_openr_file(file))
  {
    printf("arquivo aberto\n");
  }
  f_validate_and_start_buffer(file, file_buffer);
  printf("buffer state %s", file->buffer);
}
