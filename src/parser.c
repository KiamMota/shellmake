#include "interpreter/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


PARSER_STRUCT* ps_init_parser(char* buffer)
{
  PARSER_STRUCT* ps = malloc(sizeof(PARSER_STRUCT));
  if (!ps) return NULL;
  ps->buffer = strdup(buffer);
  if (!ps->buffer) { free(ps); return NULL; }
  ps->index = ps->buffer; 
  ps->state = PSS_IDLE;
  return ps;
}

void ps_destroy_parser(PARSER_STRUCT** ps)
{
  if(ps && *ps) free(*ps);
  *ps = NULL;
}

int ps_find_context(char** buffer)
{
  char* pos = strstr(*buffer, SHM_METAC_FLAG);
  if (pos){
    *buffer = pos;
  };
  return 0;
}

int ps_find_endcontext(char** buffer)
{
  char *pos = strstr(*buffer, SHM_METAC_ENDFLAG);
  if(pos) return 1;
  return 0;
}

