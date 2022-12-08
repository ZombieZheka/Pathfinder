#include "../inc/pathfinder.h"

void mx_print_path(char *from, char *to, t_list *way);

void mx_print_paths(char **verticles, t_list *bridges) {
    t_list *adj_list = mx_create_adjacency_list((const char**)verticles, bridges);
    // беремо першу вершину, вказівник на масив переміщаємо на наступну вершину
    for (char* verticle; *(verticles + 1) != NULL;) {
        verticle = *verticles++;
        // виконуємо пошук в ширину
        mx_bfs(verticle, &adj_list);
        for (int i = 0; verticles[i] != NULL; i++) {
            t_list *paths = mx_find_shortest_paths(verticles[i], &adj_list);
            for (t_list *way = paths; way != NULL; way = way->next) {
                mx_print_path(verticle, verticles[i], way);
            }
            mx_del_adj_list(&paths);
        }
    }
    mx_del_adj_list(&adj_list);
}

void mx_print_path(char *from, char *to, t_list *way) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(from);
    mx_printstr(" -> ");
    mx_printstr(to);
    char *route = NULL;
    char *distance = NULL;
    for (t_list *road = ((t_list*)way->data)->next; road != NULL; road = road->next) {
        char *temp = route;
        route = mx_strjoin(" -> ", route);
        mx_strdel(&temp);
        temp = route;
        route = mx_strjoin(((t_length_to*)road->data)->to, route);
        mx_strdel(&temp);
        temp = distance;
        char *num = mx_itoa(((t_length_to*)road->data)->length);
        distance = mx_strjoin(num, distance);
        mx_strdel(&num);
        mx_strdel(&temp);
        if (road->next != NULL) {
            temp = distance;
            distance = mx_strjoin(" + ", distance);
            mx_strdel(&temp);
        }
    }
    char *temp = route;
    route = mx_strjoin(route, ((t_length_to*)((t_list*)way->data)->data)->to);
    mx_strdel(&temp);
    mx_printstr("\nRoute: ");
    mx_printstr(route);
    mx_strdel(&route);

    if (((t_list*)way->data)->next->next != NULL) {
        temp = distance;
        distance = mx_strjoin(distance, " = ");
        mx_strdel(&temp);
        temp = distance;
        char *num = mx_itoa(((t_length_to*)((t_list*)way->data)->data)->length);
        distance = mx_strjoin(distance, num);
        mx_strdel(&num);
        mx_strdel(&temp);
    }
    mx_printstr("\nDistance: ");
    mx_printstr(distance);
    mx_strdel(&distance);
    mx_printstr("\n========================================\n");
}
