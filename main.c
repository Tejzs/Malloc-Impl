#include <stdio.h>
#include "my_malloc.h"

struct foo {
    int a;
    int b;
};

int main(int argc, char const *argv[])
{
    printf("malloc implementation\n\n");

    struct foo *test1 = create(sizeof(struct foo));
    test1->a = 10;
    test1->b = 20;

    struct foo *test2 = create(sizeof(struct foo));
    test2->a = 1;
    test2->b = 2;

    struct foo *test3 = create(sizeof(struct foo));
    test3->a = 66;
    test3->b = 55;

    free_block(test2);

    struct foo *test4 = create(sizeof(struct foo));
    test4->a = 66;
    test4->b = 55;

    free_block(test1);
    free_block(test4);
    free_block(test3);

    int *test5 = create(100);
    printf("%d", test5[0]);
    free_block(test5);
    return 0;
}
