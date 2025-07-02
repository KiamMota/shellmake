#include <string.h>
#include <stdlib.h>

#ifndef _PARSE_H_
#define _PARSE_H_

#define SHM_METAC_FLAG "!shm"
#define SHM_METAC_ENDFLAG "!eshm"

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
  char* index;
  char* context;
  PARSER_STATES state;
} PARSER_STRUCT;

PARSER_STRUCT* ps_init_parser(char* buffer);
void ps_destroy_parser(PARSER_STRUCT** ps);

int ps_find_context(char** ps);
int ps_find_endcontext(char** ps);
void parser_pipe(PARSER_STRUCT* ps);


#endif
