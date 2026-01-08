# Malloc Impl (Not very perfect!!)
This is my own implementation of `malloc()` in C, with functions to allocate and free memory manually.

## Methods
- `void* create(size_t size)` Allocates memory of given size in heap using `sbrk` method.
- `int free_block(void *ptr)` frees the allocated memory.
- `void init_debug()` Prints a heap usage report, includes: Total allocations, Total frees, Live blocks, Live bytes, and Leak detection status.
## Implementation Details
- Each allocation has associated metadata stored in a linkedlist, which keeps track of size, if free and next block.
- When a new allocation is requested, new block is created or the allocator reuses the first free block that fits.
- Freed blocks are marked as free, allowing future allocations to reuse efficiently.