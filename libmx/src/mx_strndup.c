#include <stdlib.h>

char* mx_strnew(int);
int mx_strlen(const char*);
char* mx_strncpy(char*, const char*, int);

char *mx_strndup(const char *s1, size_t n) {
    if (s1 == NULL)
        return NULL;

    size_t length = (size_t)mx_strlen(s1);
    length = length > n ? n : length;
    char *s2 = mx_strnew(length);
    return mx_strncpy(s2, s1, length);
}
