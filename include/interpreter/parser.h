#include <string.h>
#include <stdlib.h>

#ifndef _PARSE_H_
#define _PARSE_H_

typedef enum
{
  IDLE,
  READING,
  IN_CONTEXT,
  READING_CONTEXT,
  END_CONTEXT,  
  EOF
} PARSER_STATE;

typedef struct
{
  char* p_tochr;
  char* context;
  PARSER_STATE state;
} PARSER_STRUCT;

PARSER_STRUCT* ps_init_parser();
void ps_destroy_parser(PARSER_STRUCT** ps);

int find_context(PARSER_STRUCT* ps, char* buffer);
int find_endcontext(PARSER_STRUCT* ps, char* buffer);

#endif
