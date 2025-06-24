#include <stdio.h>
#include "file/shfile.h"
#include "string_validation.h"
#include "parse.h"

int main(int argn, char* args[])
{
  char file_context[1024];
  printf("file to read: ");
  /* string_validate pipeline*/
  
  fgets(file_context, sizeof(file_context), stdin);
  
  validate_shf_suffix(file_context);
  remove_nl(file_context);  
  if(f_file_exists(file_context))
  {
    FILE_STRUCT* file = f_init_file(file_context);
    printf("arquivo existe! \n");
  }else
  {
    printf("arquivo não existe");
  }

}
