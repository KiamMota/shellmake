#include <stdlib.h>

#ifndef _EVENTS_H_
#define _EVENTS_H_

typedef enum
{
  SHMEV_START,
  SHMEV_FILE_OPENED,
  SHMEV_FILE_CLOSED,
  SHMEV_ERROR,
  /* PARSING EVENTS*/
  SHMEV_PARSE_START,
  SHMEV_PARSE_RUNNING,

} SHMAKE_EVENT;

SHMAKE_EVENT* init_event();

#endif

