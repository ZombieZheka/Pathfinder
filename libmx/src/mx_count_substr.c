#include <stddef.h>

int mx_strlen(const char*);
int mx_get_substr_index(const char*, const char*);

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    for (int index; (index = mx_get_substr_index(str, sub)) >= 0; count++)
        str += mx_strlen(sub) + index;
    return (str == NULL || sub == NULL) ? -1 : count;
}
