#include "../inc/libmx.h"

void mx_clear_list(t_list **list) {
    while (*list != NULL)
        mx_pop_front(list);
}
