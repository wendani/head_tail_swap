#include <stdlib.h>
#include <stdio.h>

struct node {
	int val;
	struct node *next;
};

struct node *head_tail_swap(struct node *node);

int main(int argc, char *argv[])
{
	int i;
	struct node *head, *p;

	head = NULL;
	for (i = 0; i < 10; i++) {
		p = (struct node *)malloc(sizeof(struct node));
		p->val = i;

		p->next = head;
		head = p;
	}

	head = head_tail_swap(head);

	while (head) {
		p = head->next;

		printf("val = %d\n", head->val);
		free(head);

		head = p;
	}

	return 0;
}
