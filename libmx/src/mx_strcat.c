#include <stddef.h>

int mx_strlen(const char*);
char* mx_strncpy(char*, const char*, int);

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    if (s1 == NULL || s2 == NULL)
        return NULL;
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    mx_strncpy(s1 + len1, s2, len1 + len2 + 1);
    if (s1 != NULL)
        s1[len2 + len1 + 1] = '\0';
    return s1;
}
