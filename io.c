
#include "cli/io.h"
#include "cli/defines.h"
#include <stdio.h>

void log_printf(COLOR C, const char* literal)
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
  printf("-> %s", literal);
  SET_WHITE();
}
