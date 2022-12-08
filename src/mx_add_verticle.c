#include "../inc/pathfinder.h"

void mx_add_verticle(char ***arr, char* verticle) {
    if (verticle == NULL)
        return;

    if (*arr == NULL) {
        *arr = (char**)malloc(2 * sizeof(char*));
        (*arr)[0] = mx_strdup(verticle);
        (*arr)[1] = NULL;
        return;
    }

    if (!mx_is_new(*arr, verticle))
        return;

    int size = mx_strarr_length((const char**)(*arr)) + 1;
    char** new_arr = malloc((size + 1) * sizeof(char*));
    for (int i = 0; (*arr)[i] != NULL; i++)
        new_arr[i] = mx_strdup((*arr)[i]);
    new_arr[size - 1] = mx_strdup(verticle);
    new_arr[size] = NULL;
    mx_del_strarr(arr);
    *arr = new_arr;
}
