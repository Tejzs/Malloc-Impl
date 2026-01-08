#ifndef my_malloc_H
#define my_malloc_H    

#include <stdlib.h>
#include <stdio.h>

// Metadata for each allocated memory block
// Stores size, free status, and link to the next block
typedef struct block {
    size_t size; // size of the memory space (excluding metadata)
    int free; // 0 if allocated, 1 if free
    struct block *next; // pointer to the next block in the linked list
} t_block;

// Count of total allocations
static int total_allocated = 0;
// Count of total frees
static int total_freed = 0;
// head of the linked list
static t_block *head = NULL;

// Allocates memory of the given size in the heap and returns a pointer to it
extern void *create(size_t size);
// Reallocates memory of the given memory space and size in the heap and returns a pointer to it
extern void *recreate(void *ptr, size_t size);

// Frees the previously allocated memory pointed to by ptr
// Returns 1 on success, -1 if ptr is invalid
extern int free_block(void *ptr);

extern void find_memory_leaks();

extern void init_debug();
#endif
