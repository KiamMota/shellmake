#include "pipeline/lexer.h"
#include <string.h>

char* substr(char* root, int st, int end)
{
		int eph_len = strlen(root);
		int len = end - st +1;
		char* sub = malloc(len * sizeof(char));
		strncpy(sub, root + st, len);
		return sub;
}

void test_lexing(char *buffer, TOKEN_ARR* tk)
{
		long len = strlen(buffer);
		int left = 0;
		int right = 0;	

		while(right <= len)
		{
				if(buffer[right] == 'a' && left == right)
				{
						char* sub = substr(buffer, left, right);
						left = right;
						printf("sub: %s\n", sub);
				}
				right++;
		}
		printf("encerrando.");
}
