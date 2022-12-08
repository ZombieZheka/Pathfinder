#include "../inc/pathfinder.h"
#include <limits.h>

// чекаем твои мостики на валидность/инвалидность
int mx_check_bridges_is_valid(t_list **bridges) {
    // тут по каждому мостику проходимся
    int length = 0;
    int line_num = 1;
    for (t_list *i = *bridges; i != NULL; i = i->next, line_num++, length += ((t_bridge*)i->data)->length) {
        if (INT_MAX - ((t_bridge*)i->data)->length -1 <= length) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            return -7;
        }
        if (mx_strcmp(((t_bridge*)i->data)->start, ((t_bridge*)i->data)->end) == 0 // чтоб мост вел на другой остров
        || ((t_bridge*)i->data)->length <= 0) { // тут смотрим чтобьі мостик бьіл с длинной нормальной
            char *msg = mx_strdup("error: line ");
            msg = mx_strcat(mx_strcat(msg, mx_itoa(line_num)), " is not valid\n");
            mx_printerr(msg);
            mx_strdel(&msg);
            return -5;
        }
        // тут будем чекать чтобьі тьі не строил мостик через остров, если он уже есть
        if (i->next == NULL)
            break;
        for (t_list *j = i->next; j != NULL; j = j->next) {
            if ((mx_strcmp(((t_bridge*)i->data)->start, ((t_bridge*)j->data)->start) == 0
            && mx_strcmp(((t_bridge*)i->data)->end, ((t_bridge*)j->data)->end) == 0)
            || (mx_strcmp(((t_bridge*)i->data)->start, ((t_bridge*)j->data)->end) == 0
            && mx_strcmp(((t_bridge*)i->data)->end, ((t_bridge*)j->data)->start) == 0)) {
                mx_printerr("error: duplicate bridges\n");
                return -6;
            }
        }
    }
    return 0;
}
