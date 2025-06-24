
#include "parse.h"

int find_start(char* string)
{
  if(!string) return -1;
  char* pos = strstr(string, "# ! start shmake");
  if(pos != NULL) 
  {
    int size= (int)(pos - string);
    return size;
  }
  return -1;
}

int find_end(char* string)
{
  if(!string) return -1;
  char* pos = strstr(string, "# ! end shmake");
  if(pos != NULL)
  {
    int index = (int)(pos - string);
    return index;
  }
  return -1;
}
