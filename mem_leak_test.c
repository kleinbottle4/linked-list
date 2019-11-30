#include "node.h"

void allocate_mem(int);

int main(int argc, const char **argv)
{
    int count, size;
    count = atoi(argv[1]);
    size = atoi(argv[2]);
    for (int i = 0; i < count; i++) {
        allocate_mem(size);
        printf("%d, ", i);
    }
    putchar('\n');
    puts("Press enter to exit.");
    getchar();
    return 0;
}

void allocate_mem(int size)
{
    struct node *list = list_new(1);
    for (int i = 0; i < size; i++) {
        list_push(list, 1);
    }
    list_destroy(list);
}
