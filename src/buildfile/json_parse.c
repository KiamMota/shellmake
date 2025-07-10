// ==> this code have local functions to encapsulate of iterations in json build file
// they are not in h file

#include "buildfile/bfile.h"
#include "strvec.h"
#include "cJSON.h"
#include "event_list.h"
#include <stdio.h>

char*		_json_str_obj(cJSON* root, char* str_cmd);
BOOL		_json_obj_bool(cJSON* root, char* str_cmd);
strvec_t*	_json_obj_arrstr(cJSON* root, char* str_cmd);

/*==================================*/ 
/*==================================*/ 
/*==================================*/ 

void bcmd_json_parse(BUILD_CMD* bcmd, char* buffer)
{
		cJSON* json_parse = cJSON_Parse(buffer);
		cJSON* cmd;
		strvec_t* strvec = strvec_alloc();
		if(json_parse == NULL)
		{
				const char* c_json_err = cJSON_GetErrorPtr();
				printf("json parse error: %s", c_json_err);
				cJSON_Delete(json_parse);
		}
		bcmd->cmd_filename = _json_str_obj(json_parse, "file_name");
		bcmd->sa_distro_exclude = _json_obj_arrstr(json_parse, "distro_exclude");

}
/*==================================*/ 
/*==================================*/
/*==================================*/ 

BOOL _json_obj_bool(cJSON* root, char* str_cmd)
{
		cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
		if(!cJSON_IsBool(cmd))
		{
				cJSON_Delete(cmd);
				evlist_log(GLOBAL_EVLIST, "CJSON PARSING ERR -> [is not an bool]");
				return GENERIC_ERR;
		}
		return (cJSON_IsTrue(cmd)) ? TRUE : FALSE;
}

char* _json_str_obj(cJSON* root, char* str_cmd)
{
		cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd); 		
		if(!cJSON_IsString(cmd) && !cmd->valuestring)
		{
				cJSON_Delete(cmd);
				evlist_log(GLOBAL_EVLIST, "JSON PARSING ERR -> [invalid command]");
				return "invalid";
		}
		printf("valor-> %s", cmd->valuestring);
		return cmd->valuestring;
}

strvec_t* _json_obj_arrstr(cJSON* root, char* str_cmd)
{
		strvec_t* json_strvec = strvec_alloc();
		cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
		cJSON* get_in_array;
		int arr_size = cJSON_GetArraySize(cmd);

		if(!cJSON_IsArray(cmd) && cJSON_IsNull(cmd))
		{	
				cJSON_Delete(cmd);
			    evlist_log(GLOBAL_EVLIST, "-> CJSON ERROR [is not an array]");	
				return NULL;
		}
		for(int i = 0; i<arr_size; i++)
		{
				get_in_array = cJSON_GetArrayItem(cmd, i);	
				char* array_item_str = cJSON_Print(get_in_array);
				strvec_insert(json_strvec, array_item_str);
		}
		cJSON_Delete(cmd);
		return json_strvec;
}

