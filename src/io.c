
#include "cli/io.h"
#include "cli/defines.h"
#include <stdio.h>

void log_printf(COLOR C, const char* literal, short brk_line)
{
  switch (C) {
  default:
    SET_WHITE();
    break;
  case LOG_GREEN:
    SET_GREEN();    
    break;
  case LOG_YELLOW:
    SET_ORANGE();
    break;
   case LOG_RED:
    SET_RED();
    break;
  } 
  if (!brk_line) printf("%s", literal);
  else
  {
    for(short i = 0; i<brk_line; i++)
    {
      printf("%s", literal);
      printf("\n"); 
    }  
  }
  fflush(stdout);
  SET_WHITE();
}
