#include <stdlib.h>

char* mx_strnew(int size) {
    char *str = (size < 0) ? NULL : malloc(size + 1);
    for (int i = 0; i <= size; str[i] = '\0', i++);
    return str;
}
