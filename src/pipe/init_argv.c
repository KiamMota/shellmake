#include "pipe/init_argv.h"
#include <string.h>

// ==> this function gets the filelist getted by the argv and returns a strvec_t and
// existing files

strvec_t* _validate_existing_files(strvec_t* filelist, char* suffix)
{
		strvec_t* valid_files = strvec_alloc();
		for(short i =1; i<strvec_get_lines(filelist); i++)
		{
				if(strstr(filelist->_arr[i], suffix))
				{
						if(f_file_exists(filelist->_arr[i]))
						{
								printf("file '%s' exists.\n", filelist->_arr[i]);
								strvec_insert(valid_files, filelist->_arr[i]);	
						}
				}else
				printf("file '%s' doesn't exists\n", filelist->_arr[i]);
		}

		return valid_files;
}

void init_argv(int argn, char** argv)
{
		strvec_t* filelist = strvec_alloc();

		for(int i =1; i<argn; i++)
		{
				if(strstr(argv[i], ".sh"))
				{
						strvec_insert(filelist, argv[i]);
				}
		}

		strvec_printall(filelist);
}

