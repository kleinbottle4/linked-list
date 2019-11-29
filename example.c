/*
 * Copyright 2019 Syed Shah
 * GPL v3 - See the LICENSE file at the root of this project tree
 */

#include <stdio.h>
#include "node.h"

void node_sizes(void)
{
	printf("Size of node struct: %d bytes\n", sizeof(struct node));
	printf("Size of NODE_T: %d bytes\n",      sizeof(NODE_T));
	printf("Size of NODE_T ptr: %d bytes\n",  sizeof(NODE_T*));
}

void node_debug(struct node *head)
{
	node_sizes();
	struct node *p = head;
	for (int i = 0; p != NULL; p = p->next, i++) {
		printf("%d) address: %p val: %d next: %p\n", i, p, p->val, p->next);
	}
}

int main(void)
{
	struct node *head = list_new(1);
	for (int i = 2; i <= 20; i++) {
	       list_push(head, i);
	}
	node_debug(head);
	int tmp;
    bool err_flag;
	for (int i = 1; i <= 20; i++) {
		tmp = list_pop(&head, &err_flag);
		printf("%d\n", tmp);
	}
	/*trying to pop an empty list*/
	/*list_pop(&head);*/
	return 0;
}
