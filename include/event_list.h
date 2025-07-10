#include <stdlib.h>
#include <stdio.h>
#include "strvec.h"
#ifndef _GLOBAL_ELIST_H_
#define _GLOBAL_ELIST_H_

typedef enum
{
		SHMEV_GL_DEALLOC, // ==> 0	
		SHMEV_GL_ALLOC,
		SHMEV_GL_ERROR   = 99,
		
		SHMEV_FL_OPEN    = 1,
		SHMEV_FL_CLOSE   = 2,
		SHMEV_FL_READ    = 3,
		SHMEV_FL_WRITE   = 4,
} EVENTS;

typedef struct
{
		long list_lenght;	
		EVENTS* events;
		strvec_t* log_vec;
} event_list;

extern event_list* GLOBAL_EVLIST;

event_list* evlist_alloc(void);
void evlist_add(event_list* elist, EVENTS ev);
void evlist_log(event_list* evlist, char* message);
void evlist_show_all_log(event_list* evlist);
void evlist_show_events(event_list* evlist);

#endif
