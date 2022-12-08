#include <stddef.h>

char* mx_strcpy(char *dst, const char *src) {
    if (dst == NULL || src == NULL)
        return NULL;

    char *ptr = dst;
    while ((*dst++ = *src++) != '\0');
    return ptr;
}
