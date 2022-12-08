#include <stddef.h>

int mx_strlen(const char*);
int mx_get_char_index(const char*, char);

int mx_count_words(const char *str, char delimiter) {
    int count = (str == NULL ? -1 : *str == '\0' ? 0 : 1);
    for (int shift; (shift = mx_get_char_index(str, delimiter)) >= 0; count += shift == 0 ? 0 : 1)
        str += 1 + shift;
    return count - (str != NULL && str[mx_strlen(str) - 1] == delimiter ? 1 : 0);
}
