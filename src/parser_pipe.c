#include "interpreter/parser.h"
#include <stdio.h>
#include <string.h>

void parser_pipe(PARSER_STRUCT* ps)
{
  while(*ps->index != '\0')
  {
    if(ps_find_context(&ps->index))
    {
      printf("@");
      continue;
    }
      printf("[%c]", *ps->index);
      ps->index++;
  }
}

