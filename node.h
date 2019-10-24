#ifndef _NODE
#define _NODE

#ifndef node_t
#define node_t int
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
	node_t val;
	struct node *next;
};

struct node *make_node(node_t);
struct node *get_end(struct node *);
void push(struct node *, node_t);
node_t pop(struct node **);
struct node *get_node(struct node *, int);
bool insert(struct node *, int, node_t);

struct node *make_node(node_t val)
{
	struct node *p = malloc(sizeof(struct node));
	p->next = NULL;
	p->val = val;
	return p;
}

struct node *get_end(struct node *head)
{
	struct node *p = head;
	if (p == NULL) {
		perror("Cannot get end of empty list!");
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

node_t pop(struct node **p_head)
{
	struct node *head = *p_head;
	if (head == NULL) {
		perror("Cannot pop empty list!");
		exit(1);
	} else if (head->next == NULL) {
		node_t val = head->val;
		free(head);
		*p_head = NULL;
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

struct node *get_node(struct node *head, int index)
{
    struct node *p = head;
    while (index > 0) {
        if (p == NULL)
            return NULL;
        else
            p = p->next;
    }
    return p;
}

bool insert(struct node *head, int index, node_t val)
{
    struct node *p = get_node(head, index);
    if (p == NULL) {
        return true;
    } else {
        struct node *q = p->next;
        struct node *n = malloc(sizeof(struct node));
        n->val = val;
        n->next = q;
        p->next = n;
        return false;
    }
}
#endif
