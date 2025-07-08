#include "buildfile/buildfille.h"
#include "buildfile/buildfile_cmd.h"
#include "cJSON.h"
#include <stdio.h>

const char* json_str_obj(cJSON* root, char* str_cmd);
int json_obj_bool(cJSON* root, char* str_cmd);
char** json_obj_arrstr(cJSON* root, char* str_cmd);

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

char** result = json_obj_arrstr(buffer_to_parse, BCMD_DISTRO_ORIGINS);
  if(result)
  {
    printf("valores da array: %s", *result);
  }
  
  cJSON_Delete(cmd);
  cJSON_Delete(buffer_to_parse);
}

const char* json_str_obj(cJSON* root, char* str_cmd)
{
  cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
  if(cJSON_IsString(cmd) && cmd->valuestring != NULL)
    return cmd->valuestring;
  return "null";
}

int json_obj_bool(cJSON* root, char* str_cmd)
{
  cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
  if(cJSON_IsBool(cmd))
  {
    if(cJSON_IsTrue(cmd))  return 1;
    if(cJSON_IsFalse(cmd)) return 0;
  } 
    return -1;
}

char** json_obj_arrstr(cJSON* root, char* str_cmd)
{
  cJSON* cmd = cJSON_GetObjectItemCaseSensitive(root, str_cmd);
  if(cJSON_IsArray(cmd))
  {
    cJSON* item = cmd->child;
    while(item)
    {
      if(cJSON_IsString(item))
      {
      }
      item = item->next;
    }
  }
}





