#include "events.h"

SHMAKE_EVENT* init_event()
{
  SHMAKE_EVENT* shellmake_event_ptr = malloc(sizeof(int));
  shellmake_event_ptr = SHMEV_PARSE_START;  
}
