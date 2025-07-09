#include "strvec.h"
#include <stdlib.h>
#include <string.h>

strvec_t* strarr_alloc()
{
	strvec_t* strarr_st = malloc(sizeof(strvec_t));
	strarr_st->arr = malloc(sizeof(char));
	strarr_st->line_len = 0;	
	return strarr_st;
}

void strarr_destroy(strvec_t** strarr)
{
	for(int i = 0; i<(*strarr)->line_len; i++)
	{
		free((*strarr)->arr[i]);
	}
}

void strarr_insert(strvec_t* strarr, char* cstr)
{
	strarr->arr = realloc(strarr->arr, (strarr->line_len + 1) * sizeof(char*));
	strarr->arr[strarr->line_len] = malloc(strlen(cstr) + 1);
	strcpy(strarr->arr[strarr->line_len], cstr);
	strarr->line_len ++;

}
