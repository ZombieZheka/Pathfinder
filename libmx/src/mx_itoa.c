#include <stdlib.h>

double mx_pow(double, int);

char* mx_itoa(int number) {
    int mark = (number < 0) ? -1 : 1;
    
    int i = 10;
    for (; i != -1 && mx_pow(10, i) > (number / 10) * mark; i--);
    i += 2;
    
    char* line = malloc(i + (mark == -1 ? 2 : 1));
    line[i + (mark == -1 ? 1 : 0)] = '\0';
    if (mark == -1)
        line[0] = '-';

    for (int j = (mark == -1) ? 1 : 0; i > 0; i--, j++)
        line[j] = (number / (int)mx_pow(10, i - 1)) % 10 * mark + '0';
    return line;
}
