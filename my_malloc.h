#ifndef my_malloc_H
#define my_malloc_H    

#include <stdlib.h>
#include <stdio.h>

// Metadata for each allocated memory block
// Stores size, free status, and link to the next block
typedef struct block
{
    size_t size;            // size of the memory space (excluding metadata)
    int free;               // 0 if allocated, 1 if free
    struct block *next;     // pointer to the next block in the linked list
} t_block;

// head of the linked list
static t_block *head = NULL;
// Allocates memory of the given size in the heap and returns a pointer to it
extern void* create(size_t size);
// Frees the previously allocated memory pointed to by ptr
// Returns 1 on success, -1 if ptr is invalid
extern int free_block(void *ptr);
#endif