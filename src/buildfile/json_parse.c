#include "buildfile/bfile.h"
#include "strvec.h"
#include "cJSON.h"
#include <stdio.h>

const char* _json_str_obj(cJSON* root, char* str_cmd);
int _json_obj_bool(cJSON* root, char* str_cmd);
strvec_t* _json_obj_arrstr(cJSON* root, char* str_cmd);

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

}

strvec_t* _json_obj_arrstr(cJSON* root, char* str_cmd)
{
		strvec_t* json_strvec = strvec_alloc();
		cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
		cJSON* element = NULL;
		cJSON* array = NULL;

		if(!cJSON_IsArray(cmd) && cJSON_IsNull(cmd))
		{	
				cJSON_Delete(cmd);
				return NULL;
		}
		
		int arr_size = cJSON_GetArraySize(cmd);
		printf("array size: %d", arr_size);
}
