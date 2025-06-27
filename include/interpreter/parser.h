#include <string.h>
#include <stdlib.h>

#ifndef _PARSE_H_
#define _PARSE_H_

typedef enum 
{
  PSS_IDLE,
  PSS_READING,
  PSS_IN_CONTEXT,
  PSS_READING_CONTEXT,
  PSS_END_CONTEXT,  
  PSS_EOF
} PARSER_STATES;

typedef struct
{
  char* buffer;
  char* p_tochr;
  char* context;
  PARSER_STATES state;
} PARSER_STRUCT;

PARSER_STRUCT* ps_init_parser(char* buffer);
void ps_destroy_parser(PARSER_STRUCT** ps);

int find_context(PARSER_STRUCT* ps);
int find_endcontext(PARSER_STRUCT* ps);

int ps_read_file(PARSER_STRUCT* ps);


#endif
