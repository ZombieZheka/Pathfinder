#include <unistd.h>

void *mx_realloc(void*, size_t);

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 0 || fd < 0) {
        return -2;
    }

    char buffer[1];
    (*lineptr) = (char*)mx_realloc(*lineptr, buf_size);
    if (read(fd, &buffer, 1))
        if (buffer[0] == delim)
            return 1;
    return 2;
}
