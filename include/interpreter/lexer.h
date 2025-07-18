#include <string.h>
#include <stdlib.h>

#ifndef _LEXER_H_
#define _LEXER_H_

typedef enum
{
		METAC_FLAG, 
		MRTH, 
		SYMBOL,
		OPAREN, 
		CPAREN, 
		COLON, 
		DOUBLE_QUOTE, 
		LITERAL_STRING, 
		METAC_ENDFLAG,
} TOKENS;

void test_init_lexing(char* buffer);

#endif


