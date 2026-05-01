#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "my_malloc.h"

void test_basic_alloc() {
    void *ptr = create(64);
    assert(ptr != NULL);
    free_block(ptr);
    printf("PASS: test_basic_alloc\n");
}

void test_zero_alloc() {
    void *ptr = create(0);
    // behaviour is implementation-defined, just shouldn't crash
    if (sizeof(ptr) > 0) {
        printf("FAILED: test_zero_alloc\n");
        exit(1);
    } else {
        printf("PASS: test_zero_alloc\n");
    }
}

void test_multiple_allocs() {
    void *a = create(32);
    void *b = create(64);
    void *c = create(128);
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(a != b && b != c);
    free_block(a);
    free_block(b);
    free_block(c);
    printf("PASS: test_multiple_allocs\n");
}

int main() {
    test_basic_alloc();
    test_zero_alloc();
    test_multiple_allocs();
    printf("All tests passed!\n");
    return 0;  // return 0 = pass, non-zero = fail
}