#include <stddef.h>

unsigned long mx_hex_to_nbr(const char *hex) {
	if (hex == NULL)
		return 0;

	unsigned long nbr = 0;
	int length = 0;
	int hextech = 1;
	for (; hex[length] != '\0'; length++);
	for (int i = length - 1; i >= 0; i--) {
		if (hex[i] >= '0' && hex[i] <= '9')
			nbr += (hex[i] - '0') * hextech;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			nbr += (hex[i] - 'A' + 10) * hextech;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			nbr += (hex[i] - 'a' + 10) * hextech;
		else
			return 0;
		hextech *= 16;
	}
	return nbr;
}
