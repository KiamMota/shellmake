#include <stdio.h>
#include "file/shfile.h"
#include "string_validation.h"
#include "parse.h"

int main(int argn, char* args[])
{
  
  char file_name[1024];
  char* file_buffer;

  printf("file to read: ");
  /* string_validate pipeline*/
  
  fgets(file_name, sizeof(file_name), stdin);
  
  validate_shf_suffix(file_name);
  remove_nl(file_name);  
  if(f_file_exists(file_name))
  {
    FILE_STRUCT* file = f_init_file(file_name);
    if(f_openr_file(file))
    {
      printf("o arquivo foi aberto para leitura \n");
      f_buffer_init(file);
    }else printf("o arquivo não foi aberto \n");
    printf("%s", file->buffer);
  }else
  {
    printf("arquivo não existe");
  }

}
