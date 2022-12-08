#include "../inc/pathfinder.h"

t_list *mx_find_in_adjacency_list(char *name, t_list **adjacency_list) {
    for (t_list *i = *adjacency_list; i != NULL; i = i->next) {
        if (mx_strcmp(((t_length_to*)((t_list*)i->data)->data)->to, name) == 0) {
            return i;
            //return (t_length_to*)((t_list*)i->data)->data;
        }
    }
    return NULL;
}
