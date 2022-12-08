void mx_printchar(char);

void mx_printint(int n) {
    int mark = (n < 0) ? -1 : 1;
    if (mark == -1)
        mx_printchar('-');

    int i = 1000000000;
    for (; i > (n / 10) * mark; i /= 10);
    i = (i == 0) ? 1 : i * 10;
    for (; i > 0; i /= 10)
        mx_printchar((n / (i)) % 10 * mark + '0');
}
