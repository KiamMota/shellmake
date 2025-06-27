#include "cli/io.h"
#include "file/shfile.h"
#include "file/string_validation.h"
#include "interpreter/parser.h"
#include <stdio.h>
#include <threads.h>

int main(int argn, char *args[]) {
  char file_name[1024];
  char *file_buffer;

  printf("file to read: ");
  /* string_validate pipeline*/

  fgets(file_name, sizeof(file_name), stdin);
  log_printf(LOG_YELLOW, " -> validating suffix...", 1);
  validate_shf_suffix(file_name);
  remove_nl(file_name);
  log_printf(LOG_YELLOW, " -> initing struct of file...", 1);
  FILE_STRUCT *file = f_init_file(file_name);
  if (!f_file_exists(file->file_name)) {
    f_destroy_file(&file);
    log_printf(LOG_WHITE, "cannot open the file: ", 0);
    printf("\"%s\" ", file_name);
    printf("(is this exists?) \n");
    return 1;
  }
  f_openr_file(file);
  log_printf(LOG_GREEN, " -> opened ", 0);
  printf("\"%s\" \n", file_name);
  if(f_start_buffer(file, &file_buffer))
  {
    log_printf(LOG_GREEN, " -> started buffer", 1);
  }
  log_printf(LOG_GREEN, " -> reading to read", 1);
  printf("TO DEBUG: %s GUBED\n", file_buffer);

}
