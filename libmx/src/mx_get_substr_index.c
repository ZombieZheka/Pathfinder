#include <stddef.h>

int mx_strlen(const char*);
int mx_get_char_index(const char*, char);
int mx_strncmp(const char*, const char*, int);

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL)
        return -2;

    for (int index = 0, length = mx_strlen(sub) - 1, shift; (shift = mx_get_char_index(str + index, *sub)) >= 0; index++) {
        index += shift;
        if (mx_strncmp(str + index, sub, length) == 0)
            return index;
    }
    return -1;
}
