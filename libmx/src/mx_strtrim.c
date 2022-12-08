#include <stddef.h>
#include <stdbool.h>

char *mx_strnew(int);
bool mx_isspace(char);
int mx_strlen(const char*);

char *mx_strtrim(const char *str) {
    if (str == NULL)
        return NULL;
    int start = 0, end = mx_strlen(str) - 1;
    for (; mx_isspace(str[start]); start++);
    for (; mx_isspace(str[end]) && end >= start; end--);

    if (end - start <= 0)
        return mx_strnew(0);
    char *trim_str = mx_strnew(1 + end - start);
    for (int i = 0; start <= end; i++)
        trim_str[i] = str[start++];
    return trim_str;
}
