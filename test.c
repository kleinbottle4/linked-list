#include "node.h"
#include <stdio.h>
#include <stdbool.h>

void print_all(struct node *);

int main(void)
{
    struct node *list = make_node(10);
    for (int i = 9; i >= 1; i--)
        push(list, i);
    
    print_all(list);
    if ((insert(&list, 0, 100)) == true)
        puts("error");
    else
        puts("success");

    print_all(list);

    return 0;
}

void print_all(struct node *head)
{
    for (struct node *p = head; p != NULL; p = p->next)
        printf("%d, ", p->val);
    putchar('\n');
}
