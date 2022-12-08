#include <stddef.h>

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *s_ptr = s;
    if (s != NULL)
        for (size_t i = 0; s_ptr[i] != '\0' && i != n + 1; i++)
            if (s_ptr[i] == (unsigned char)c)
                return (void*)(s_ptr + i);
    return NULL;
}
