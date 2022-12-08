#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
	int size = 0;
	for (t_list *node = list; node != NULL; size++)
		node = node->next;
	return size;
}
