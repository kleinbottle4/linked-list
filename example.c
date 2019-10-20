#include <stdio.h>
#include "node.h"

void node_sizes(void)
{
	printf("Size of node struct: %d bytes\n", sizeof(struct node));
	printf("Size of node_t: %d bytes\n", sizeof(node_t));
	printf("Size of node_t ptr: %d bytes\n", sizeof(node_t*));
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
	struct node *head = make_node(1);
	for (int i = 2; i <= 20; i++) {
	       push(head, i);
	}
	node_debug(head);
	int tmp;
	for (int i = 1; i <= 20; i++) {
		tmp = pop(&head);
		printf("%d\n", tmp);
	}
	/*trying to pop an empty list*/
	/*pop(&head);*/
	return 0;
}
