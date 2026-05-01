#include "my_malloc.h"

struct foo {
    int a;
    int b;
};

int main(int argc, char const *argv[]) {
    init_debug();
    struct foo *test1 = create(sizeof(struct foo));
    test1->a = 10;
    test1->b = 20;
    free_block(test1);
    return 0;
}
