#include <stddef.h>

char *mx_strnew(int);
int mx_strlen(const char*);
char* mx_strncpy(char*, const char*, int);
int mx_strncmp(const char*, const char*, int);
int mx_count_substr(const char*, const char*);
void mx_strdel(char**);

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL)
        return NULL;
    
    int sub_length = mx_strlen(sub);
    int rep_length = mx_strlen(replace);
    int len = mx_strlen(str) + mx_count_substr(str, sub) * rep_length - sub_length;
    char *rep_str = mx_strnew(len);
    for (int i = 0; i < len; i++, str++) {     
        if (mx_strncmp(str, sub, sub_length - 1) == 0) {
            mx_strncpy(&rep_str[i], replace, rep_length);
            i += rep_length - 1;
            str += sub_length - 1;
        }
        else
            rep_str[i] = str[0];
    }
    return rep_str;
}
