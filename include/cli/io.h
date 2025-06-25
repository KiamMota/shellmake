
#ifndef _CLI_IO_H_
#define _CLI_IO_H_

typedef enum
{
  LOG_RED = 1,
  LOG_YELLOW,
  LOG_GREEN,
  LOG_WHITE
} COLOR;

void log_printf(COLOR C, const char* literal);



#endif
