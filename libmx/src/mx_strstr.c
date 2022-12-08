#include <stddef.h>

int mx_get_substr_index(const char*, const char*);

char *mx_strstr(const char *haystack, const char *needle) {
    int index = mx_get_substr_index(haystack, needle);
    return (index < 0) ? NULL : (char*)haystack + index;
}
