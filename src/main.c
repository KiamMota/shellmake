#include "file/file_struct.h"
#include "file/string_validation.h"
#include "buildfile/buildfile_cmd.h"
#include "buildfile/buildfille.h"
#include <stdio.h>

int main(int argn, char *args[]) 
{
  char file_name[255];
  char* buffer;
  printf("nome do arquivo: ");
  fgets(file_name, 255, stdin);
  f_validate_suffix(file_name, ".json");
  f_remove_nl(file_name);
  if(!f_file_exists(file_name))
  {
    printf("arquivo não existe!");
  }
    printf("file existe!");
    FILE_STRUCT* file_context = f_init_file(file_name);
    f_openr_file(file_context);
    f_start_buffer(file_context);
    f_get_fs_buffer(file_context, &buffer);
    f_destroy_file(&file_context);
    BUILD_CMD* bcmd = bcmd_init();
    bcmd_json_parse(bcmd, buffer);

}
