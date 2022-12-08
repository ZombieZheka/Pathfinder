#include <stddef.h>

void mx_printchar(char);

void mx_printstr(const char *s) {
    while (s != NULL && *s != '\0') {
        mx_printchar(*s++);
    }
}
