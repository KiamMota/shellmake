#include <stdlib.h>
#include <stdio.h>
#include "shared/strvec.h"
#ifndef _GLOBAL_ELIST_H_
#define _GLOBAL_ELIST_H_

typedef struct
{
		long list_lenght;	
		// EVENTS* events;
		strvec_t* log_vec;
} event_list;

extern event_list* GLOBAL_EVLIST;

event_list* evlist_alloc(void);
void evlist_log(event_list* evlist, char* message);
void evlist_show_all_log(event_list* evlist);

#endif
