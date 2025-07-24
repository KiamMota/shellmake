// ==> this file represents the strvec type, a shellmake specific type to represents
// string arrays with basic functions to alloc, destroy and insert
// TODO: delete some specific string in the array 

#include "shellmake.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef _STRVEC_H_
#define _STRVEC_H_

typedef struct{
	char** _arr;
	long _line_len;
} strvec_t;

strvec_t* strvec_alloc();
void strvec_destroy(strvec_t** strarr);
void strvec_insert(strvec_t* strarr, char* cstr);
long strvec_get_lines(strvec_t* strvec);
void strvec_printall(strvec_t* strvec);
#endif
