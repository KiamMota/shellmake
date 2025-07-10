#include "event_list.h"

event_list* GLOBAL_EVLIST = NULL;

event_list* evlist_alloc(void)
{
		event_list* allocated_evlist = malloc(sizeof(event_list));
		allocated_evlist->list_lenght = 0;
		allocated_evlist->log_vec = strvec_alloc();
		return allocated_evlist;

}

void evlist_add(event_list* elist, EVENTS ev)
{
     elist->events = realloc(elist->events, (elist->list_lenght + 1) * sizeof(long));
	 elist->events[elist->list_lenght] = ev;
     elist->list_lenght++;
}

void evlist_log(event_list *evlist, char *message)
{
		strvec_insert(evlist->log_vec, message);
}

void evlist_show_all_log(event_list *evlist)
{
		printf("LOG OCCURRENCES [%ld] -> ", strvec_get_lines(evlist->log_vec));
		for(long i=0; i<strvec_get_lines(evlist->log_vec); i++)
				{
						printf(" [%ld] | ", strvec_get_lines(evlist->log_vec));
					    printf("%s\n", evlist->log_vec->_arr[i]);	
				}
}

void evlist_show_events(event_list *evlist)
{
for(long i=0; i<evlist->list_lenght; i++)		
printf("-> %d\n", evlist->events[i]);

}
