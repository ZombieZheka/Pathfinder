#include <stdlib.h>
#include "../inc/libmx.h"

void mx_pop_front(t_list **list) {
	if (*list == NULL)
		return;
	t_list *node = (*list)->next;
	free((*list)->data);
    free(*list);
    *list = node;
}
