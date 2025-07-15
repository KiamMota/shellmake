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
		strvec_t* sh_invalids = strvec_alloc();
		for(short i =0; i<strvec_get_lines(filelist); i++)
		{
				if(!f_file_exists(filelist->_arr[i])) 
						strvec_insert(sh_invalids, filelist->_arr[i]);	
		}
		return sh_invalids;
}

void init_argv(int argn, char** argv)
{
		if(argn <=1 )
		{
				_menu_help(); return;
		}

		strvec_t* param_invalids = strvec_alloc();
		strvec_t* sh_invalids = strvec_alloc();
		strvec_t* bfile_invalids = strvec_alloc();

		strvec_t* filelist    = strvec_alloc();
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

// ==> inserting in string vectors

		for(int i =1; i<argn; i++)
		{	
				if(strstr(argv[i], ".sh"))
						strvec_insert(filelist, argv[i]);
				if(strstr(argv[i], ".json"))
						strvec_insert(eph_buildflist, argv[i]);
				if(!strstr(argv[i], ".json") && !strstr(argv[i], ".sh"))
						strvec_insert(param_invalids, argv[i]);
		}
	    
		printf("validating parameters...");

		if(strvec_get_lines(param_invalids))
		{
				printf("	fail.\n");
				for(short i = 0; i<strvec_get_lines(param_invalids); i++)
						printf("| '%s'\n", param_invalids->_arr[i]);	
				printf("incorrectly written or invalid files.\n");
		}

		printf("done.\n");

// ==> inserting in invalid files list

		sh_invalids			= _get_invalid_files(filelist);
		bfile_invalids	= _get_invalid_files(eph_buildflist);

		long total_invalids = strvec_get_lines(sh_invalids) + strvec_get_lines(bfile_invalids);

		printf("validating files...");
		
		if(strvec_get_lines(filelist) == 0)
		{
				printf("	fail.\n");
				printf("shell files are required! \n");

				return;
		}

		if(total_invalids)
		{
				printf("	fail.\n");
				for(short i=0; i<strvec_get_lines(sh_invalids); i++)
						printf("| '%s' \n", sh_invalids->_arr[i]);
				
				if(strvec_get_lines(bfile_invalids))
				{	
						for(int j=0; j<strvec_get_lines(bfile_invalids); j++)
								printf("| '%s' \n", bfile_invalids->_arr[j]);
				}
						
						printf("-> %ld file(s) not found.\n", total_invalids);	
						printf("--- ABORTED ---\n ");
						return;
		}	
		
		strvec_destroy(&param_invalids);
		strvec_destroy(&sh_invalids);
		strvec_destroy(&bfile_invalids);


		printf("done.\n");
}

