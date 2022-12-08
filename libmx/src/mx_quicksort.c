#include <stddef.h>

int mx_strlen(const char*);
void mx_strswap(char**, char**);

int mx_quicksort(char **array, int left, int right) {
    if (array == NULL)
        return -1;

    if(left >= right)
        return 0;
    int count = 0;
    int pivot = mx_strlen(array[left + (right - left)/2]);
    int leftI = left-1;
    int rightI = right+1;
    
    while(1) {
        while(mx_strlen(array[++leftI]) < pivot);
        while(mx_strlen(array[--rightI]) > pivot);
        if(leftI >= rightI)
            break;
        mx_strswap(&array[leftI], &array[rightI]);
        count++;
    }
    mx_quicksort(array,left,rightI);
    mx_quicksort(array,rightI+1,right);
    return count;
}
