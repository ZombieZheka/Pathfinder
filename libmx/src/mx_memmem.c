#include <stddef.h>

int mx_memcmp(const void*, const void*, size_t);

void * mx_memmem(const void * big, size_t big_len, const void *little, size_t little_len) {
	unsigned char *where = NULL;
	unsigned char *what = NULL;

	if (big && little && big_len >= little_len && big_len > 0 && little_len > 0) {
		where = (unsigned char *)big;
		what = (unsigned char *)little;
		for (; *where; where++)
			if (mx_memcmp(where, what, little_len - 1) == 0)
				return where;
	}
	return NULL;
}
