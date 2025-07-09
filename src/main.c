#include "file/file_struct.h"
#include "file/string_validation.h"
#include "buildfile/cmd.h"
#include "strvec.h"
#include <stdio.h>

int main(int argn, char *args[]) 
{
	strvec_t* str = strarr_alloc();
	printf("allocatting strvec\n");
	printf("insert into vector");
	strarr_insert(str, "debian");
	strarr_insert(str, "ubuntu");
	strarr_insert(str, "kali");
	strarr_insert(str, "arch");

	for(int i = 0; i<str->line_len; i++)
	{
		printf("-> %s\n", str->arr[i]);
	}

	printf("deleting strvec:");

	strarr_destroy(&str);
}

