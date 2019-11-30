/*
 * node.h is a singley linked list header file.
 * Copyright (C) 2019 Syed Shah

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _LIST
#define _LIST

#ifndef NODE_T
#define NODE_T int
#endif

#ifndef DEFAULT_VAL
#define DEFAULT_VAL 0
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef _NODE
struct node {
	NODE_T val;
	struct node *next;
};
#define _NODE
#endif

struct node *list_new     (NODE_T);
struct node *list_get_end (struct node *);
struct node *list_get     (struct node *,  int);
void         list_push    (struct node *,  NODE_T);
NODE_T       list_pop     (struct node **, bool *);
bool         list_insert  (struct node **, int, NODE_T);
bool         list_remove  (struct node **, int   );
void         list_destroy (struct node *);

struct node *list_new(NODE_T val)
{
	struct node *p = malloc(sizeof(struct node));
	p->next = NULL;
	p->val = val;
	return p;
}

struct node *list_get_end(struct node *head)
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

void list_push(struct node *head, NODE_T val)
{
	if (head == NULL) {
		head = malloc(sizeof(struct node));
		head->val = val;
		head->next = NULL;
	} else {
		struct node *p = list_get_end(head);
		struct node *n = malloc(sizeof(struct node));
		n->val = val;
		n->next = NULL;
		p->next = n;
	}
}

NODE_T list_pop(struct node **p_head, bool *err_flag)
{
	struct node *head = *p_head;
	if (head == NULL) {
		*err_flag = true;
		return DEFAULT_VAL;
	} else if (head->next == NULL) {
		NODE_T val = head->val;
		free(head);
		*p_head = NULL;
        *err_flag = false;
		return val;
	} else {
		struct node *p = head;
		while ((p->next)->next != NULL)
			p = p->next;
		NODE_T val = (p->next)->val;
		free(p->next);
		p->next = NULL;
        *err_flag = false;
		return val;
	}
}

struct node *list_get(struct node *head, int index)
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

bool list_insert(struct node **p_head, int index, NODE_T val)
{
    if (index == 0) {
        struct node *n = malloc(sizeof(struct node));
        n->next = *p_head;
        n->val = val;
        *p_head = n;
        return false;
    } else {
        struct node *p = list_get(*p_head, index - 1);
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
}

bool list_remove(struct node **p_head, int index)
{
    if (index == 0) {
        struct node *old_head = *p_head;
        *p_head = (*p_head)->next;
        free(old_head);
        return false;
    } else {
        struct node *a = list_get(*p_head, index - 1);
        if (a == NULL) {
            return true;
        } else {
            struct node *b = a->next;
            struct node *c = b->next;
            a->next = c;
            free(b);
            return false;
        }
    }
}

void list_destroy(struct node *list)
{
    if (list->next)
        list_destroy(list->next);
    free(list);
}

#endif
