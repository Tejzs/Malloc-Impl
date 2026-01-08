#include "my_malloc.h"
#include <string.h>
#include <unistd.h>

void *create(size_t size) {
    void *p = sbrk(sizeof(t_block) + size);
    if (p == (void *) -1) {
        return NULL;
    }

    t_block *block = NULL;
    block = (t_block *) p;
    block->size = size;
    block->free = 0;
    block->next = NULL;

    void *user = (void *) (block + 1);

    t_block *curr = head;
    if (curr == NULL) {
        head = block;
    } else {
        while (curr->next != NULL) {
            if (curr->free == 1 && curr->size >= size) {
                block = curr;
                block->free = 0;
                user = (void *) (block + 1);
                memset(user, 0, size);
                total_allocated++;
                return user;
            }
            curr = curr->next;
        }
        curr->next = block;
    }
    memset(user, 0, size);
    total_allocated++;
    return user;
}

// Returns a pointer to the metadata block corresponding to the user pointer
t_block *get_metadata(void *ptr) {
    if (ptr == NULL) { return NULL; }
    t_block *metadata = (t_block *) ((char *) ptr - sizeof(t_block));
    return metadata;
}

int free_block(void *ptr) {
    if (ptr == NULL) { return -1; }
    t_block *block = get_metadata(ptr);
    if (block != NULL) {
        block->free = 1;
        total_freed++;
        return 1;
    }
    return -1;
}

void find_memory_leaks() {
    t_block *curr = head;
    int live_blocks = 0;
    int live_bytes = 0;
    while (curr != NULL) {
        if (curr->free == 0) {
            live_blocks++;
            live_bytes += (int) curr->size;
        }
        curr = curr->next;
    }
    printf("========== Heap Report ==========\n");
    printf("Total Allocations   : %d\n", total_allocated);
    printf("Total frees         : %d\n", total_freed);
    printf("Live blocks         : %d\n", live_blocks);
    printf("Live Bytes          : %d\n", live_bytes);
    printf("Status              : %s\n", live_blocks == 0 ? "OK" : "FAILED");
    printf("=================================");
}

void init_debug() {
    atexit(find_memory_leaks);
}
