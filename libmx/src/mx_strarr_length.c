#include <stddef.h>

int mx_strarr_length(const char **arr) {
    if (arr == NULL)
        return 0;

    int length;
    for (length = 0; arr[length] != NULL; length++);
    return length;
}
