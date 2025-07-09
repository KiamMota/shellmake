#include "shellmake.h"

#include "stdlib.h"
#include <string.h>

typedef struct{
	char** arr;
	long line_len;
} str_arr_t;

str_arr_t* strarr_alloc(str_arr_t* strarr);
void strarr_destroy(str_arr_t** strarr);
BOOL strarr_insert(str_arr_t* strarr, char* cstr);
