#include "pipe/init_argv.h"
#include <string.h>

// ==> this function gets the filelist getted by the argv and returns a strvec_t and
// existing files


#define MENU \
"\
\033[0;32mWelcome to ShellMake\033[0m\n\
Usage:\n\
  -> shellmake script.sh [script2.sh ...] [Build.json ...]\n\
\n\
Examples:\n\
  -> shellmake a.sh b.sh c.sh\n\
  -> shellmake a.sh b.sh Build.json\n\
  -> shellmake a.sh BuildA.json\n\
\n\
|Notes:\n\
|- At least one .sh file is required.\n\
|- Each .sh can have an optional matching Build.json.\n\
|- You can list all .sh first, then .json files, or pair them.\n\
|- If only one argument is given, this help is shown.\n\
|===============================================================\n"
void _menu_help()
{
		printf(MENU);
}


BOOL _existing_files(strvec_t* filelist)
{
		strvec_t* invalid_files = strvec_alloc();
		strvec_t* valid_files = strvec_alloc();
		for(short i =0; i<strvec_get_lines(filelist); i++)
		{
				if(f_file_exists(filelist->_arr[i]))
				{
						strvec_insert(valid_files, filelist->_arr[i]);	
				}
				else break; 
		}

				if(strvec_get_lines(valid_files) == strvec_get_lines(filelist))
				{
						strvec_destroy(&filelist);
						filelist = valid_files;
						return TRUE;
				}else {
						return FALSE;
				}
		
}

void init_argv(int argn, char** argv)
{
		if(argn <=1 )
		{
				_menu_help(); return;
		}
		
		strvec_t* eph_filelist = strvec_alloc();
		strvec_t* eph_buildflist = strvec_alloc();
	

		for(int i =1; i<argn; i++)
		{
				if(strstr(argv[i], ".sh"))
						strvec_insert(eph_filelist, argv[i]);
				if(strstr(argv[i], ".json"))
						strvec_insert(eph_buildflist, argv[i]);
		}
		strvec_printall(eph_buildflist);
		printf("validating shell files...");
		if(!_existing_files(eph_filelist)) 
				printf("	fail.\n");
		else printf("	success.\n");

		printf("validating build files...");
		if(!_existing_files(eph_buildflist))
				printf("	fail.\n");
		else printf("	success");
}

