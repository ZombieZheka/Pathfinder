int mx_strlen(char*);
void mx_swap_char(char*, char*);

void mx_str_reverse(char *s) {
    int length = mx_strlen(s);
    for (int i = 0; i < length / 2; i++) {
        mx_swap_char(&s[i], &s[length -1 - i]);
    }
}
