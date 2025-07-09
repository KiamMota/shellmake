// ==> this file represents the strvec type, a shellmake specific type to represents
// string arrays with basic functions to alloc, destroy and insert
// TODO: delete some specific string in the array 

#include "shellmake.h"

#ifdef DEBUG
#include <stdio.h>
#endif

#include "stdlib.h"
#include <string.h>

#ifndef _STRVEC_H_
#define _STRVEC_H_

typedef struct{
	char** arr;
	long line_len;
} strvec_t;

strvec_t* strarr_alloc();
void strarr_destroy(strvec_t** strarr);
void strarr_insert(strvec_t* strarr, char* cstr);

#endif
