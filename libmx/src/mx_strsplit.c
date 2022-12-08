#include <stdlib.h>

char* mx_strnew(int);
int mx_strlen(const char*);
int mx_count_words(const char*, char);
int mx_get_char_index(const char*, char);
char* mx_strncpy(char*, const char*, int);

char **mx_strsplit(char const *s, char c) {
	if (s == NULL)
        return NULL;
    int size = mx_count_words(s, c);
	char **words = (char**) malloc((size + 1) * sizeof(char*));
	words[size] = NULL;
    for (int i = 0; i < size; i++) {
		for (; *s == c && *s != '\0'; s++);
		int length = mx_get_char_index(s, c);
        length = length < 0 ? mx_strlen(s) : length;
		words[i] = mx_strnew(length);
		mx_strncpy(words[i], s, length);
		s += length;
	}
	return words;
}
