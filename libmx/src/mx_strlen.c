int mx_strlen(const char* s) {
    int i = 0;
    for (i = 0; s && *s++ != '\0'; i++);
    return i;
}
