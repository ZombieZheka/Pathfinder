#include "../inc/pathfinder.h"

bool mx_is_new(char **source, char *value) {
    if (source != NULL)
        for (int i = 0; source[i] != NULL; i++)
            if (mx_strcmp(value, source[i]) == 0)
                return false;
    return true;
}
