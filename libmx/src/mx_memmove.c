#include <stdlib.h>

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t);

void *mx_memmove(void *dst, const void *src, size_t len) {
	unsigned char *tmp = malloc(len);
	tmp = mx_memcpy(tmp, src, len);
	dst = mx_memcpy(dst, tmp, len);
	free(tmp);
	return dst;
}
