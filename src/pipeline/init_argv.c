#include "pipeline/init_argv.h"
#include <string.h>

// ==> this function gets the filelist getted by the argv and returns a strvec_t and
// existing files


#define HELP_MENU \
"\
\
use -help to see this menu again. \n\
\
Usage:\n\
  insert your scripts as parameters\n\
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
|- If multiple Build.json files are provided,\n\
|  -> they will be assigned to .sh files in the order given.\n\
|     (First .sh gets first .json, second .sh gets second .json, etc.)\n\
|================================================================\n"

void _menu_help() {printf(HELP_MENU);}
void _version()
{
		printf("ShellMake version %s (%s)\n", SHELLMAKE_VERSION, SHELLMAKE_STATE);
		printf("---------\n");
}

strvec_t* _get_invalid_files(strvec_t* filelist)
{
		strvec_t* invalid_files = strvec_alloc();
		int valid_files = 0;
		for(short i =0; i<strvec_get_lines(filelist); i++)
		{
				if(!f_file_exists(filelist->_arr[i])) 
						strvec_insert(invalid_files, filelist->_arr[i]);	
		}
		return invalid_files;
}

void init_argv(int argn, char** argv)
{
		if(argn <=1 ){_menu_help(); return;}
		strvec_t* invalid_files = strvec_alloc();

		strvec_t* eph_filelist    = strvec_alloc();
		strvec_t* eph_buildflist  = strvec_alloc();


		if(strcmp(argv[1], "-help") == 0)
		{
				_menu_help(); 
				return;
		}
		if(strcmp(argv[1], "-version") == 0 || strcmp(argv[1], "-v") == 0)
		{
				_version();
				return;
		}

		for(int i =1; i<argn; i++)
		{
				
				if(strstr(argv[i], ".sh"))
						strvec_insert(eph_filelist, argv[i]);
				if(strstr(argv[i], ".json"))
						strvec_insert(eph_buildflist, argv[i]);
		}

		invalid_files = _get_invalid_files(eph_filelist);
		printf("validating files...");
		if(strvec_get_lines(invalid_files))
		{
				printf("	fail.\n");
				printf("\n");
				for(short i=0; i<strvec_get_lines(invalid_files); i++)
						printf("| '%s' \n", invalid_files->_arr[i]);
			    printf("-> file(s) not found.\n");	
				printf("--- ABORTED. ---\n ");
				return;
		} 

		FILE_STRUCT* file_context[strvec_get_lines(eph_filelist)];
		for(short i=0; i<strvec_get_lines(eph_filelist); i++)
		{
				printf("opening '%s'...", eph_filelist->_arr[i]);
				file_context[i] = f_init_file(eph_filelist->_arr[i]);	
				printf("		done.\n");
		}


}

