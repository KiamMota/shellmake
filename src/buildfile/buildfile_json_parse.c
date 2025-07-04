#include "buildfile/buildfille.h"
#include "buildfile/buildfile_cmd.h"
#include "cJSON.h"

#include <stdio.h>

const char* json_var_string(cJSON* root, char* str_cmd);
int json_var_bool(cJSON* root, char* str_cmd);

void bcmd_json_parse(BUILD_CMD* bcmd, char* buffer)
{
  cJSON* buffer_to_parse = cJSON_Parse(buffer);
  cJSON* cmd;
  if(buffer_to_parse == NULL)
  {
      const char* cjson_err = cJSON_GetErrorPtr();
      printf("cjson parse error: %s", cjson_err);
      cJSON_Delete(buffer_to_parse);
  }

  // const char* result = json_var_string(buffer_to_parse, BCMD_MINIMUM_VER_REQ);
  
  if(json_var_bool(buffer_to_parse, BCMD_REQUIRED_ROOT))
  {
    printf("requer root");
  }else printf("não requer root");

  cJSON_Delete(cmd);
  cJSON_Delete(buffer_to_parse);
}

const char* json_var_string(cJSON* root, char* str_cmd)
{
  cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
  if(cJSON_IsString(cmd) && cmd->valuestring != NULL)
    return cmd->valuestring;
  return "null";
}

int json_var_bool(cJSON* root, char* str_cmd)
{
  cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
  if(cJSON_IsBool(cmd))
  {
    if(cJSON_IsTrue(cmd))  return 1;
    if(cJSON_IsFalse(cmd)) return 0;
  } 
    return -1;
}




