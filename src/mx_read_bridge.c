#include "../inc/pathfinder.h"

t_bridge *mx_read_bridge(char* str) {
    char** values = mx_strsplit(str, '-');
    if (mx_strarr_length((const char**)values) != 2 || mx_strlen(values[1]) == 0
    || mx_strlen(values[0]) + mx_strlen(values[1]) != mx_strlen(str) - 1) {
        mx_del_strarr(&values);
        return NULL;
    }
    char** end = mx_strsplit(values[1], ',');
    if (mx_strarr_length((const char**)end) != 2 || mx_strcmp(values[0], end[0]) == 0) {
        mx_del_strarr(&values);
        mx_del_strarr(&end);
        return NULL;
    }
    char* num_line = mx_strdup(end[1]);
    t_bridge *bridge = malloc(sizeof(t_bridge));
    bridge->start = mx_strdup(values[0]);
    bridge->end = mx_strdup(end[0]);
    bridge->length = mx_atoi(num_line);
    mx_del_strarr(&values);
    mx_del_strarr(&end);
    if (bridge->length == 0 && (num_line[0] != '0' || mx_strlen(num_line) != 1)) {
        mx_pop_bridge(bridge);
        free(bridge);
        bridge = NULL;
    }
    mx_strdel(&num_line);
    return bridge;
}
