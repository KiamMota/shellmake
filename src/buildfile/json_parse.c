// ==> this code have local functions to encapsulate of iterations in json build file
// they are not in h file

#include "buildfile/bfile.h"
#include "shared/strvec.h"
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

		bcmd->sa_cmd_distro_exclude = _json_obj_arrstr(json_parse, BCMD_DISTRO_EXCLUDE);
		bcmd->cmd_required_root = _json_obj_bool(json_parse, BCMD_REQUIRED_ROOT);
		bcmd->cmd_minimum_version_required = _json_str_obj(json_parse, "a");
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
		return (cJSON_IsTrue(cmd) ? TRUE : FALSE);
}

char* _json_str_obj(cJSON* root, char* str_cmd)
{
		cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd); 		
		char* to_return;
		if(cJSON_IsInvalid(cmd) || !cJSON_IsString(cmd))
		{
				cJSON_Delete(cmd);
				evlist_log(GLOBAL_EVLIST, "JSON PARSING ERR -> [invalid string]");
				return "invalid";
		}
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

