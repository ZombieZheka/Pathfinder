#include "../inc/pathfinder.h"

void mx_clear_history(t_list **adjacency_list) {
    for (t_list *i = *adjacency_list; i != NULL; i = i->next) {
        t_length_to *length_to = (t_length_to*)((t_list*)i->data)->data;
        length_to->visited = false;
        length_to->length = 0;
    }
}
