#include "interpreter/parser.h"
#include <stdlib.h>
#include <string.h>


PARSER_STRUCT* ps_init_parser(char* buffer)
{
  PARSER_STRUCT* ps = malloc(sizeof(PARSER_STRUCT));
  if (!ps) return NULL;
  ps->buffer = strdup(buffer);
  if (!ps->buffer) { free(ps); return NULL; }
  ps->p_tochr = ps->buffer; 
  ps->state = PSS_IDLE;
  return ps;
}

void ps_destroy_parser(PARSER_STRUCT** ps)
{
  if(ps && *ps) free(*ps);
  *ps = NULL;
}

int find_context(PARSER_STRUCT* ps)
{
  char* pos = strstr("buffer", " !shm");
  if (pos){
   ps->state = PSS_IN_CONTEXT;
   return *pos;
  }
  else
  {
    ps->state = PSS_READING;
    return -1;
  }
}
