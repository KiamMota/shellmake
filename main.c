#include <stdio.h>
#include "shfile.h"
#include "shf_string_validation.h"
#include "parse.h"

int main(int argn, char* args[])
{
  char file_context[1024];
  printf("file to read: ");
  /* string_validate pipeline*/
  
  fgets(file_context, sizeof(file_context), stdin);
  
  validate_shf_suffix(file_context);
  remove_nl(file_context);  
  struct file_struct* current_file = init_file(file_context);
  

}
