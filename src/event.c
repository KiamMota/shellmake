#include "events.h"

SHMEVENT* shev_init_event()
{
  SHMEVENT* shellmake_event_ptr = malloc(sizeof(int));
  *shellmake_event_ptr = SHMEV_START;
  return shellmake_event_ptr;  
}
