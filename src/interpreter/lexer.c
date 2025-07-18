#include <stdio.h>
#include "interpreter/lexer.h"

void test_init_lexing(char *buffer)
{
		char* ptr = buffer;
		while(*ptr != '\0')
		{
				printf("%c", *ptr);		
				ptr++;
		}



}
