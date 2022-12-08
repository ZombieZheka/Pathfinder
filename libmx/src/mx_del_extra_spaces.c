#include <stddef.h>
#include <stdbool.h>

char *mx_strnew(int);
bool mx_isspace(char);
void mx_strdel(char**);
int mx_strlen(const char*);
char *mx_strtrim(const char*);

char *mx_del_extra_spaces(const char* str) {
    if (str == NULL)
        return NULL;
    char* trim_str = mx_strtrim(str);
    int length = mx_isspace(trim_str[mx_strlen(trim_str) - 1]) ? -1 : 0;
    for (int i = 0; trim_str[i] != '\0'; i++) {
        if (!mx_isspace(trim_str[i]))
            length += mx_isspace(trim_str[i + 1]) ? 2 : 1;
    }
    char *del_spaces = mx_strnew(length);
    for (int i = 0, j = 0; trim_str[i] != '\0'; i++) {
        if (!mx_isspace(trim_str[i])) {
            del_spaces[j++] = trim_str[i];
            if (mx_isspace(trim_str[i + 1]))
                del_spaces[j++] = ' ';
        }
    }
    mx_strdel(&trim_str);
    return del_spaces;
}
