#include <string.h>
#include <stdlib.h>

#ifndef _LEXER_H_
#define _LEXER_H_

typedef enum
{
		SYMBOL,
		OPERATOR,
} TOKENS;

typedef struct
{
		long line;
		long column;
		char* symbol;
		TOKENS* tok;
} LEXER;

LEXER* lx_alloc(void);
void   lx_lexing(LEXER* lx, char* buffer);

#endif


