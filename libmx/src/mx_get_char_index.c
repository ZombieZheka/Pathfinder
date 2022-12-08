#include <stddef.h>

int mx_get_char_index(const char *str, char c) {
    for (int i = 0; str != NULL && str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return str == NULL ? -2 : -1;
}
