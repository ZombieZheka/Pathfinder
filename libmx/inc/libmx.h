#ifndef LIBMX_H
#define LIBMX_H

#include <stddef.h>
#include <stdbool.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}               t_list;

int mx_atoi(const char*);
int mx_binary_search(char**, int, const char*, int*);
int mx_bubble_sort(char**, int);
void mx_clear_list(t_list**);
int mx_count_substr(const char*, const char*);
int mx_count_words(const char*, char);
t_list *mx_create_node(void*);
char *mx_del_extra_spaces(const char*);
void mx_del_strarr(char***);
char *mx_file_to_str(const char*);
void mx_foreach(int*, int, void(*)(int));
int mx_get_char_index(const char *str, char c);
int mx_get_substr_index(const char*, const char*);
unsigned long mx_hex_to_nbr(const char*);
bool mx_isdigit(char);
bool mx_isspace(char);
char* mx_itoa(int);
int mx_list_size(t_list*);
void *mx_memccpy(void *restrict dst, const void *restrict src, int, size_t);
void *mx_memchr(const void*, int, size_t);
int mx_memcmp(const void*, const void*, size_t);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t);
void * mx_memmem(const void*, size_t, const void*, size_t);
void *mx_memmove(void*, const void*, size_t);
void *mx_memrchr(const void*, int, size_t);
void *mx_memset(void*, int, size_t);
char* mx_nbr_ti_hex(unsigned long nbr);
void mx_pop_back(t_list**);
void mx_pop_front(t_list**);
double mx_pow(double, unsigned int pow);
void mx_print_strarr(char**, const char*);
void mx_print_unicode(wchar_t);
void mx_printchar(char);
void mx_printerr(const char*);
void mx_printint(int);
void mx_printstr(const char*);
void mx_push_back(t_list**, void*);
void mx_push_front(t_list**, void*);
int mx_quicksort(char**, int, int);
int mx_read_line(char**, size_t, char, const int fd);
void *mx_realloc(void*, size_t);
char *mx_replace_substr(const char*, const char*, const char*);
t_list *mx_sort_list(t_list*, bool (*)(void*, void*));
int mx_sqrt(int);
void mx_str_reverse(char*);
int mx_strarr_length(const char**);
char *mx_strcat(char *restrict s1, const char *restrict s2);
int mx_strcmp(const char*, const char*);
char* mx_strcpy(char*, const char*);
void mx_strdel(char**);
char *mx_strdup(const char*);
char* mx_strjoin(char const*, char const*);
int mx_strlen(const char*);
int mx_strncmp(const char*, const char*, int);
char* mx_strncpy(char*, const char*, int);
char *mx_strndup(const char*, int);
char* mx_strnew(int);
char **mx_strsplit(char const*, char);
char *mx_strstr(const char*, const char*);
void mx_strswap(char**, char**);
char *mx_strtrim(const char*);
void mx_swap_char(char*, char*);

#endif
