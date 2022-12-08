#include <stddef.h>

int mx_strlen(const char*);
char* mx_strcat(char*, const char*);
char* mx_strnew(int);
char* mx_strdup(const char*);

char* mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL || s2 == NULL) {
        return s1 == NULL && s2 == NULL ? NULL : s1 == NULL ? mx_strdup(s2) : mx_strdup(s1);
    }
    char *str = mx_strnew(mx_strlen(s1) + mx_strlen(s2) + 1);
    mx_strcat(str, s1);
    mx_strcat(str, s2);
    return str;
}
