#include "interpreter/parser.h"
#include <string.h>

PARSER_STRUCT* ps_init_parser()
{
  PARSER_STRUCT* ps = malloc(sizeof(PARSER_STRUCT));
  ps->state = IDLE;
  ps->p_tochr = 0;
  return ps;
}

void ps_destroy_parser(PARSER_STRUCT** ps)
{
  if(ps && *ps) free(*ps);
  *ps = NULL;
}

int find_context(PARSER_STRUCT* ps, char* buffer)
{
  char* pos = strstr("buffer", "# !shm");
  /* todo */
}
