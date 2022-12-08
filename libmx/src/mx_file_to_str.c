#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

char *mx_strnew(int);
int mx_strlen(const char*);

char *mx_file_to_str(const char *filename) {
	int fd = open(filename, O_RDONLY);
	int size = 0;
	char buf;

	if (read(fd, NULL, 0) < 0 || fd == -1) {
		return NULL;
    }

	while (read(fd, &buf, 1))
		size++;
	close(fd);

	fd = open(filename, O_RDONLY);
	char *str = mx_strnew(size);
	read(fd, str, size);
	close(fd);
	return str;
}
