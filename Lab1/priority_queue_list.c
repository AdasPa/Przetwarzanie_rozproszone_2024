#include <stdio.h>
#include <stdlib.h>
#include "priority_queue_list.h"

void
qlist(pqueue *head, void (*print_data)(void *)) {
	pqueue *p;
	
	for (p = head; p != NULL; p = p->next) {
		printf("%d: ", p->k);
		print_data(p->data);
		printf("\n");
	}
	
}

void
qinsert(pqueue **phead, void *data, int k) {
	pqueue* p = *phead;
	pqueue* new_node = (pqueue*) malloc(sizeof(pqueue));

	new_node->data = data;
	new_node->k = k;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (p == NULL)
	{
		*phead = new_node;
		return;
	}

	while (k < p->k)
	{
		if (p->next == NULL)
		{
			p->next = new_node;
			new_node->prev = p;
			return;
		}

		p = p->next;
	}

	new_node->prev = p->prev;
	new_node->next = p;
	p->prev = new_node;

	if(new_node->prev != NULL)
		new_node->prev->next = new_node;
	else
		*phead = new_node;


	return;

}


void
qremove(pqueue **phead, int k) {
	pqueue* p = *phead;

	while (p->k != k)
	{
		p = p->next;
		if (p == NULL)
		{
			printf("Element of this priority doesn't exist.");
			return;
		}
	}

	if (p->prev == NULL)
	{
		*phead = p->next;
		p->next = NULL;
		return;
	}

	p->prev->next = p->next;

	if (p->next != NULL)
		p->next->prev = p->prev;

	

}

