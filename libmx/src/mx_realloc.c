#include <stdlib.h>
#if defined(__MACH__)
#include <malloc/malloc.h>
#else 
#include <malloc.h>
#endif

int mx_strlen(const char*);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t);

void *mx_realloc(void *ptr, size_t size) {
    size_t cur_size;
    void *new_ptr;
    if (ptr == 0)
	    return malloc(size);

#if defined(__MACH__)
    cur_size = malloc_size(ptr);
#else
    cur_size = malloc_usable_size(ptr);
#endif

    if (size <= cur_size)
	    return ptr;
    new_ptr = malloc(size);
    mx_memcpy(new_ptr, ptr, cur_size);
    free(ptr);
    return new_ptr;
}
