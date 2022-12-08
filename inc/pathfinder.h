#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdlib.h>
#include "../libmx/inc/libmx.h"

// структура для зберігання мостів
typedef struct s_bridge {
    char* start;
    int length;
    char* end;
}       t_bridge;

// структура для зберігання даних про мости у списку суміжностей
typedef struct s_length_to {
    char* to;
    int length;
    bool visited;
}           t_length_to;

bool mx_is_new(char**, char*);
void mx_pop_bridge(t_bridge*);
void mx_del_adj_list(t_list**);
t_bridge *mx_read_bridge(char*);
void mx_clear_history(t_list**);
void mx_bfs(const char*, t_list**);
void mx_add_verticle(char***, char*);
void mx_print_paths(char**, t_list*);
int mx_check_bridges_is_valid(t_list**);
char *mx_check_errors(int, char const*[]);
t_list *mx_find_shortest_paths(char*, t_list**);
t_list *mx_find_in_adjacency_list(char*, t_list**);
t_list *mx_create_adjacency_list(const char**, t_list*);

#endif
