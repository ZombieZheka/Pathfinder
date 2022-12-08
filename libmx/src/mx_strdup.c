#include <stdlib.h>

char *mx_strnew(int);
int mx_strlen(const char*);
char* mx_strcpy(char*, const char*);

char *mx_strdup(const char *s1) {
    if (s1 == NULL)
        return NULL;

    char *s2 = mx_strnew(mx_strlen(s1));
    return mx_strcpy(s2, s1);
}
