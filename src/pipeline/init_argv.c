#include "pipeline/init_argv.h"
#include <string.h>
#include "pipeline/lexer.h"


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

int _get_invalid_files(strvec_t* filelist, strvec_t* to_invalid)
{
		for(short i =0; i<strvec_get_lines(filelist); i++)
		{
				if(!fst_file_exists(filelist->_arr[i])) 
						strvec_insert(to_invalid, filelist->_arr[i]);	
		}
		return strvec_get_lines(to_invalid);
}

void _show_invalid_files(strvec_t* strv_invalids) 
{
		int invalid_lines = strvec_get_lines(strv_invalids);
		if(invalid_lines)
		{
				printf("	fail.\n");
				for(short i=0; i<invalid_lines; i++)
				{
						printf("| '%s'\n", strv_invalids->_arr[i]);
				}
				printf("invalid or incorrectly written parameters.\n");
				return;
		}
		printf("	done.\n");
}

void init_argv(int argn, char** argv)
{
		if(argn <=1 )
		{
				_menu_help(); return;
		}

		strvec_t* invalid_files = strvec_alloc(); 

		strvec_t* filelist    = strvec_alloc();
		strvec_t* bfilelist  = strvec_alloc();


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
						strvec_insert(bfilelist, argv[i]);
				if(!strstr(argv[i], ".json") && !strstr(argv[i], ".sh"))
						strvec_insert(invalid_files, argv[i]);
		}
	   

		_get_invalid_files(filelist, invalid_files);
		_get_invalid_files(bfilelist, invalid_files);
		
		printf("validating parameters...");
		
		if(strvec_get_lines(invalid_files))
		{
				_show_invalid_files(invalid_files);
				strvec_destroy(&invalid_files);
				strvec_destroy(&filelist);
				strvec_destroy(&bfilelist);
				return;
		}

		printf("	done.\n");
	
		FILE_STRUCT* file_context = fst_alloc(filelist->_arr[0]);
		TOKEN_ARR* tk = malloc(sizeof(TOKEN_ARR));
		tk->size = 0;
		fst_openr(file_context);
		fst_start_buffer(file_context);
		test_lexing(file_context->buffer, tk);	

}

