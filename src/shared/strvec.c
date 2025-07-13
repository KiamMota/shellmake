#include "shared/strvec.h"

strvec_t* strvec_alloc()
{
	strvec_t* strarr_st = malloc(sizeof(strvec_t));
	strarr_st->_arr = malloc(sizeof(char));
	strarr_st->_line_len = 0;	
	return strarr_st;
}

void strvec_destroy(strvec_t** strarr)
{
	for(int i = 0; i<(*strarr)->_line_len; i++) free((*strarr)->_arr[i]);
	
	free(*strarr);
	
	*strarr = NULL;
}

void strvec_insert(strvec_t* strarr, char* cstr)
{
	strarr->_arr = realloc(strarr->_arr, (strarr->_line_len + 1) * sizeof(char*));
	strarr->_arr[strarr->_line_len] = malloc(strlen(cstr) + 1);
	strcpy(strarr->_arr[strarr->_line_len], cstr);
	strarr->_line_len ++;

}

long strvec_get_lines(strvec_t *strvec)
{
return strvec->_line_len;
}

void strvec_printall(strvec_t *strvec)
{
		if(strvec->_line_len <=0) 
		{
		printf(" | empty list... |\n");
		return;
		}
				printf(" | line lenght: %ld\n", strvec->_line_len);
				printf(" |-----------------\n");
		for(long i=0; i<strvec->_line_len; i++) printf(" | [%ld] -> [%s]\n", i, strvec->_arr[i]);
		printf(" |-----------------\n");
		
}
