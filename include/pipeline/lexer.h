#include "shared/shellmake.h"

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#ifndef _LEXER_H_
#define _LEXER_H_

typedef enum
{
		SYMBOL,
		METAC_FLAG, 
		MRTH, 
		OPAREN, 
		CPAREN, 
		COLON, 
		DOUBLE_QUOTE, 
		LITERAL_STRING, 
		METAC_ENDFLAG,
} TOKENS;

typedef struct
{
		TOKENS* tok;
		char*   value;
		long size;
} TOKEN_ARR;

void test_lexing(char* buffer, TOKEN_ARR* tk);

#endif


