#include <stddef.h>

char* mx_strncpy(char *dst, const char *src, int n) {
    if (dst == NULL || src == NULL || n <= 0)
        return NULL;

    char *ptr = dst;
    for (int i = 0; i < n && *src != '\0'; i++)
        *dst++ = *src++;
    return ptr;
}
