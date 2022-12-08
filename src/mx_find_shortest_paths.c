#include "../inc/pathfinder.h"

void mx_dfs(t_list*, t_list**, t_list**);

t_list *mx_find_shortest_paths(char *end, t_list **adjacency_list) {
    t_length_to *length_to = malloc(sizeof(t_length_to));
    t_list *end_point = (t_list*)mx_find_in_adjacency_list(end, adjacency_list)->data;
    length_to->to = mx_strdup(((t_length_to*)end_point->data)->to);
    length_to->length = ((t_length_to*)end_point->data)->length;
    t_list *paths = mx_create_node(mx_create_node(length_to));
    mx_dfs(end_point, adjacency_list, &paths);
    return paths;
}

// Функція здійснює пошук у глибину, за кожен прохід вона порівнює, чи є вершина частиною найкоротшого шляху.
// Якщо це правда, то додає її у кінець останнього підсписку path.
// Якщо це не перша така вершина у підсписку, то копіює останній підсписок у кінець path і лише потім додає вершину
// verticle - вказівник на список суміжних з нашою вершин
// adjacency_list - список суміжностей
// paths - список шляхів від end до start
void mx_dfs(t_list *verticle, t_list **adjacency_list, t_list **paths) {
    // точка, для якої виконується пошук
    t_length_to *length_to = (t_length_to*)verticle->data;
    // вказує на те, чи слід додавати ще один шлях до списку шляхів
    bool first = true;

    // проходимося по сусіднім вершинам
    for (t_list *i = verticle->next; i != NULL; i = i->next) {
        // дорога до сусідньої вершини
        t_length_to *road = (t_length_to*)i->data;
        // сама вершина
        t_length_to *road_point = (t_length_to*)((t_list*)mx_find_in_adjacency_list(road->to, adjacency_list)->data)->data;
        // якщо порахована відстань та різниця відстаней вершини і сусіда співпадають, то додаємо сусіда до шляху
        if (length_to->length - road->length == road_point->length) {
            // j - вказівник на останню ланку шляхів
            t_list *j;
            for (j = *paths; j->next != NULL; j = j->next);
            // якщо це не перший сусід, що утворює найкоротший шлях, то робимо розвилку
            if (!first) {
                // новий шлях
                t_list *k = NULL;
                // доки не дійшли до оброблюваної вершини, копіюємо останній шлях
                t_list *last = NULL;
                for (last = (t_list*)j->data; last != NULL
                && mx_strcmp(length_to->to, ((t_length_to*)last->data)->to) != 0; last = last->next) {
                    // нова вершина
                    t_length_to *new_verticle = malloc(sizeof(t_length_to));
                    new_verticle->to = mx_strdup(((t_length_to*)last->data)->to);
                    new_verticle->length = ((t_length_to*)last->data)->length;
                    mx_push_back(&k, new_verticle);
                }
                t_length_to *new_verticle = malloc(sizeof(t_length_to));
                new_verticle->to = mx_strdup(((t_length_to*)last->data)->to);
                new_verticle->length = ((t_length_to*)last->data)->length;
                mx_push_back(&k, new_verticle);
                mx_push_back(paths, k);
                for (j = *paths; j->next != NULL; j = j->next);
            }
            t_length_to *new_verticle = malloc(sizeof(t_length_to));
            new_verticle->to = mx_strdup(road->to);
            new_verticle->length = road->length;
            t_list* temp = (t_list*)j->data;
            mx_push_back(&temp, new_verticle);
            first = false;

            // виконуємо пошук для кожної доданої вершини
            mx_dfs((t_list*)mx_find_in_adjacency_list(road->to, adjacency_list)->data, adjacency_list, paths);
        }
    }
}
