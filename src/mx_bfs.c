#include "../inc/pathfinder.h"

void mx_bfs(const char *start, t_list **adjacency_list) {
    mx_clear_history(adjacency_list);
    
    t_list *queue = mx_create_node(mx_strdup(start)); // queue
    ((t_length_to*)((t_list*)mx_find_in_adjacency_list(queue->data, adjacency_list)->data)->data)->visited = true;
    while (queue != NULL) {
        t_list *i = mx_find_in_adjacency_list(queue->data, adjacency_list);
        mx_pop_front(&queue);
        
        for (t_list* j = ((t_list*)i->data)->next; j != NULL; j = j->next) {
            t_length_to *length_to = (t_length_to*)((t_list*)
                mx_find_in_adjacency_list(((t_length_to*)j->data)->to, adjacency_list)->data)->data;
            if (!length_to->visited) {
                mx_push_back(&queue, mx_strdup(((t_length_to*)j->data)->to));
                length_to->length = ((t_length_to*)((t_list*)i->data)->data)->length + ((t_length_to*)j->data)->length;
                length_to->visited = true;
                length_to = NULL;
            }
            else if (length_to->length > ((t_length_to*)((t_list*)i->data)->data)->length
            + ((t_length_to*)j->data)->length) {
                length_to->length = ((t_length_to*)((t_list*)i->data)->data)->length
                + ((t_length_to*)j->data)->length;
                //length_to->visited = false;
            }
        }
        //t_length_to *temp = mx_create_node();
    }
    
    //for (t_list *i = ((t_list*)adj_current->data); i != NULL; i = i->next) {

    //}
    return;
}
