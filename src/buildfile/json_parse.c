#include "buildfile/bfile.h"
#include "strvec.h"
#include "cJSON.h"
#include <stdio.h>

const char* _json_str_obj(cJSON* root, char* str_cmd);
int _json_obj_bool(cJSON* root, char* str_cmd);
strvec_t* _json_obj_arrstr(cJSON* root, char* str_cmd);

void bcmd_json_parse(BUILD_CMD* bcmd, char* buffer)
{
  cJSON* buffer_to_parse = cJSON_Parse(buffer);
  cJSON* cmd;
  if(buffer_to_parse == NULL)
  {
      const char* c_json_err = cJSON_GetErrorPtr();
      printf("c_json parse error: %s", c_json_err);
      cJSON_Delete(buffer_to_parse);
  }
}


const char* _json_str_obj(cJSON* root, char* str_cmd)
{
  cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
  if(cJSON_IsString(cmd) && cmd->valuestring != NULL)
    return cmd->valuestring;
  return "null";
}

int _json_obj_bool(cJSON* root, char* str_cmd)
{
  cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
  if(cJSON_IsBool(cmd))
  {
    if(cJSON_IsTrue(cmd))  return 1;
    if(cJSON_IsFalse(cmd)) return 0;
  } 
    return -1;
}


