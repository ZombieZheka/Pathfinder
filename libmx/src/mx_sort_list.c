#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
	if (list == NULL || cmp == NULL)
		return NULL;
    for (t_list *i = list; i != NULL; i = i->next) {
            for (t_list *j = list; j->next; j = j->next) {
                if (cmp(j->data, j->next->data)) {
					void *temp = j->data;
					j->data = j->next->data;
					j->next = temp; 
                }
            } 
        }
    return list;
}
