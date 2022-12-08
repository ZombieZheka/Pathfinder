#include <stddef.h>

void mx_strswap(char**, char**);
int mx_strcmp(const char*, const char*);

int mx_bubble_sort(char **arr, int size) {
    if (arr == NULL || size <= 0)
        return -1;

    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            if (mx_strcmp(arr[j - 1], arr[j]) > 0) {
                    count++;
                    mx_strswap(&arr[j - 1], &arr[j]);
            }
        }
    }
    return count;
}
