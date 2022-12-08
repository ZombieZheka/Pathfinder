#include "../inc/pathfinder.h"

t_list* mx_create_adjacency_list(const char **verticles, t_list *bridges) {
    t_list *head = NULL;
    int length = mx_strarr_length(verticles);
    for (int i = 0; i < length; i++) {
        t_length_to *bridge_to = malloc(sizeof(t_length_to));
        bridge_to->to = mx_strdup(verticles[i]);
        bridge_to->length = 0;
        bridge_to->visited = false;
        mx_push_back(&head, mx_create_node(bridge_to));
        //mx_push_back(&head, mx_create_node(mx_strdup(verticles[i])));
    }
    //t_list *current = head;
    for (t_list *i = head; i != NULL; i = i->next) {
        for (t_list *j = bridges; j != NULL; j = j->next) {
            t_list *nested_list = (t_list*)i->data;
            if (mx_strcmp(((t_length_to*)nested_list->data)->to, ((t_bridge*)(j->data))->start) == 0) {
                t_length_to *bridge_to = malloc(sizeof(t_length_to));
                bridge_to->to = mx_strdup(((t_bridge*)(j->data))->end);
                bridge_to->length = ((t_bridge*)(j->data))->length;
                bridge_to->visited = false;
                mx_push_back(&nested_list, bridge_to);
                //mx_push_back(&nested_list, mx_strdup(((t_bridge*)j->data)->end));
            }
            else if (mx_strcmp(((t_length_to*)nested_list->data)->to, ((t_bridge*)(j->data))->end) == 0) {
                t_length_to *bridge_to = malloc(sizeof(t_length_to));
                bridge_to->to = mx_strdup(((t_bridge*)(j->data))->start);
                bridge_to->length = ((t_bridge*)(j->data))->length;
                bridge_to->visited = false;
                mx_push_back(&nested_list, bridge_to);
                //mx_push_back(&nested_list, mx_strdup(((t_bridge*)j->data)->start));
            }
        }
    }
    return head;
}
