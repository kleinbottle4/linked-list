#ifndef node_t
#define node_t int
#endif

#include <stdbool.h>
#include <stdlib.h>

struct node {
	node_t val;
	struct node *next;
};

struct node *make_node(node_t val) {
	struct node *p = malloc(sizeof(struct node));
	p->next = NULL;
	p->val = val;
	return p;
}

struct node *get_end(struct node *head) {
	struct node *p = head;
	if (p == NULL) {
		perror("Cannot get end of empty list!\n");
		exit(1);
	} else if (p->next == NULL) {
		return p;
	} else {
		struct node *q = p->next;
		while (q->next != NULL) {
			p = q;
			q = q->next;
		}
		return q;
	}
}

void push(struct node *head, node_t val)
{
	if (head == NULL) {
		head = malloc(sizeof(struct node));
		head->val = val;
		head->next = NULL;
	} else {
		struct node *p = get_end(head);
		struct node *n = malloc(sizeof(struct node));
		n->val = val;
		n->next = NULL;
		p->next = n;
	}
}

node_t pop(struct node *head)
{
	if (head == NULL) {
		perror("Cannot pop empty list!\n");
		exit(1);
	} else if (head->next == NULL) {
		node_t val = head->val;
		free(head);
		head = NULL;
		return val;
	} else {
		struct node *p = head;
		while ((p->next)->next != NULL)
			p = p->next;
		node_t val = (p->next)->val;
		free(p->next);
		p->next = NULL;
		return val;
	}
}

