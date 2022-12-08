#include "../inc/pathfinder.h"

void mx_del_adj_list(t_list **adj_list) {
    for (t_list *i = *adj_list; *adj_list != NULL; i = *adj_list) {
        for (t_list *j = (t_list*)i->data; j != NULL; mx_pop_front(&j)) {
            mx_strdel(&((t_length_to*)j->data)->to);
        }
        *adj_list = (*adj_list)->next;
        free(i);
    }
}
