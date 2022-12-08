#include <limits.h>

char* mx_strnew(int);

char* mx_nbr_to_hex(unsigned long nbr) {
    int size = 1;
	for (unsigned long i = 16; nbr / i > 0; i *= 16) {
		size++;
		if (ULONG_MAX / 16 < i)
			break;
	}

	char *hex = mx_strnew(size);
	for (int i = size - 1; i >= 0; i--) {
		hex[i] = (nbr % 16 < 10) ? (nbr % 16) + '0' : (nbr % 16 - 10) + 'a';
		nbr -= nbr % 16;
		nbr /= 16;
	}
	return hex;
}
