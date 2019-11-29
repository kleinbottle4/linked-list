/*
 * Copyright (C) 2019 Syed Shah
 * GPL v3 - See the LICENSE file at the root of this project tree
 */

#include "node.h"
#include <stdio.h>
#include <stdbool.h>

void print_all(struct node *);

int main(void)
{
    struct node *list = list_new(10);
    for (int i = 9; i >= 1; i--)
        list_push(list, i);
    
    print_all(list);
    if ((list_insert(&list, 0, 100)) == true)
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
