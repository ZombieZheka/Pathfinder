#include "../inc/pathfinder.h"

int main(int argc, char const *argv[]) {
    // читаємо вміст файлу та перевіряємо на синтаксичні помилки
    char* file = mx_check_errors(argc, argv);
    // ділимо вміст на рядки
    char** lines = mx_strsplit(file, '\n');
    mx_strdel(&file);

    int count = mx_atoi(lines[0]);
    if (count <= 0) {
        mx_printerr("error: line 1 is not valid\n");
        mx_del_strarr(&lines);
        exit(-1);
    }
    // створюємо мости
    t_list* bridges = NULL;
    for (int i = 1; lines[i] != NULL; i++) {
        t_bridge *bridge = mx_read_bridge(lines[i]);
        if (bridge != NULL)
            mx_push_back(&bridges, bridge);
        else {
            char *temp = mx_itoa(i + 1);
            char *msg = mx_strjoin("error: line ", temp);
            mx_strdel(&temp);
            temp = msg;
            msg = mx_strjoin(msg, " is not valid\n");
            mx_strdel(&temp);
            mx_printerr(msg);
            mx_strdel(&msg);
            while (bridges != NULL) {
                mx_pop_bridge((t_bridge*)bridges->data);
                mx_pop_front(&bridges);
            }
            mx_del_strarr(&lines);
            exit(-1);
        }
    }
    mx_del_strarr(&lines);
    // перевіряємо логічні помилки
    int error_num = mx_check_bridges_is_valid(&bridges);
    if (error_num < 0) {
        while (bridges != NULL) {
            mx_pop_bridge((t_bridge*)bridges->data);
            mx_pop_front(&bridges);
        }
        exit(error_num);
    }

    // відокремлюємо вершини
    char **verticles = NULL;
    for (t_list *current = bridges; current != NULL; current = current->next) {
        mx_add_verticle(&verticles, ((t_bridge*)current->data)->start);
        mx_add_verticle(&verticles, ((t_bridge*)current->data)->end);
    }

    if (count == mx_strarr_length((const char**)verticles))
        mx_print_paths(verticles, bridges);
    else
        mx_printerr("error: invalid number of islands\n");
    
    mx_del_strarr(&verticles);
    // видаляємо мости
    while (bridges != NULL) {
        mx_pop_bridge((t_bridge*)bridges->data);
        mx_pop_front(&bridges);
    }
    return 0;
}
