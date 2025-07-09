#include "str_arr.h"
#include <stdlib.h>

str_arr_t* strarr_alloc(str_arr_t* strarr)
{
	str_arr_t* strarr_st = malloc(sizeof(str_arr_t));
	strarr_st->line_len = 0;	
	return strarr;
}

void strarr_destroy(str_arr_t** strarr)
{
	if (strarr && *strarr) {
		free((*strarr)->arr);
		free(*strarr);	
		*strarr = NULL;
	}
}

BOOL strarr_insert(str_arr_t* strarr, char* cstr)
{
	if (!strarr) return GENERIC_ERR;
	strarr->arr = realloc(cstr, strlen(cstr));
	strarr->line_len +=1;
	return TRUE;
}
