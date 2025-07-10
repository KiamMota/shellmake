#include "buildfile/bfile.h"
#include "buildfile/cmd.h"
#include "strvec.h"
#include <stdio.h>

int main(int argn, char *args[]) 
{
		char filename[20];
		printf("enter the build file name:");
		fgets(filename, sizeof(filename), stdin);
		BUILDFILE* file = bf_init(filename);
		bf_init_parsing(file);		

}

