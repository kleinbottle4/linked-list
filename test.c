/*
 * Copyright (C) 2019 Syed Shah
 * GPL v3 - See the LICENSE file at the root of this project tree
 */

#include "node.h"
#include <stdio.h>
#include <stdbool.h>

void print_vals(struct node *);
void print_ptrs(struct node *);
void print_info(struct node *);
void mem_tracer(int *, int);

int main(void)
{
    struct node *list = list_new(10);

    for (int i = 9; i >= 1; i--)
        list_push(list, i);

    if ((list_insert(&list, 0, 100)) == true)
        puts("error");
    else
        puts("success");

    print_info(list);
    list_destroy(list);
    return 0;
}

void print_vals(struct node *head)
{
    for (struct node *p = head; p != NULL; p = p->next)
        printf("%d, ", p->val);
    putchar('\n');
}

void print_ptrs(struct node *head)
{
    for (struct node *p = head; p != NULL; p = p->next) {
        printf("%p\n", p);
    }
}

void print_info(struct node *head)
{
    for (struct node *p = head; p != NULL; p = p->next) {
        printf("%p\t%d\t%p\n", p, p->val, p->next);
    }
}

