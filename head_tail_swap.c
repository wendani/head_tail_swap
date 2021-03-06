#include <stdlib.h>

struct node {
    // add a value field to make test case easier
    int val;
    struct node *next;
};

struct node *head_tail_swap(struct node *head) {
    struct node *prev, *nxt;
    struct node *h, *h_next;

    // empty list
    if (!head)
        return NULL;

    // single node
    if (!head->next)
        return head;

    // two nodes
    h = head;
    h_next = h->next;
    if (!h_next->next) {
        h_next->next = h;
        h->next = NULL;
        return h_next;
    }

    // more than two nodes
    prev = h;
    nxt = h_next;
    while (nxt->next) {
        prev = nxt;
        nxt = nxt->next;
    }
    nxt->next = h_next;
    prev->next = h;
    h->next = NULL;
    return nxt;
}


void head_tail_swap_dptr(struct node **head) {
	struct node *prev, *nxt;
	struct node *h, *h_next;

	if (!head)
		return;

	h = *head;
	// empty list
	if (!h)
		return;

	// single node
	h_next = h->next;
	if (!h_next)
		return;

	// two nodes
	if (!h_next->next) {
		h_next->next = h;
		h->next = NULL;
		*head = h;
		return;
	}

	// more than two nodes
	prev = h;
	nxt = h_next;
	while (nxt->next) {
		prev = nxt;
		nxt = nxt->next;
	}
	// when we reach here,
	// nxt points to the tail node
	nxt->next = h_next;
	prev->next = h;
	h->next = NULL;
	*head = nxt;
}
