#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *cmp1 = NULL, *cmp2 = NULL, *aux = NULL;

	if (list == NULL || *list == NULL)
		return;
	if ((*list)->next == NULL)
	{
		print_list(*list);
		return;
	}
	cmp1 = *list;
	print_list(*list);
	while(cmp1->next != NULL)
	{
		cmp2 = cmp1->next;
		aux = cmp1->next->next;
		if (cmp1->n > cmp2->n)
		{
			if (cmp1->prev == NULL)
				*list = cmp2;
			else
				cmp1->prev->next = cmp2;
			cmp2->prev = cmp1->prev;
			cmp2->next = cmp1;
			cmp1->prev = cmp2;
			cmp1->next = aux;
			if (aux != NULL)
				aux->prev = cmp1;
			print_list(*list);
			cmp1 = *list;
			continue;
		}
		else
			cmp1 = cmp1->next;
	}
}

/**
 * 75, 15, 91, 24, 22, 64
 * head = 75;
 * 75->next = 15; 75->prev = NULL
 * 15->prev = 75; 15->next = 91
 * -----
 * head = 15;
 * 15->next = 75; 15->prev = NULL
 * 75->next = 91; 75->prev = 15
 *
 * 15, 75, 91, 24, 22, 64
 * 15, 75, 24, 91, 22, 64
 * 15, 24, 75, 91, 22, 64
 * 15, 24, 75, 22, 91, 64
 * 15, 24, 22, 75, 91, 64
 * 15, 22, 24, 75, 91, 64
 * 15, 22, 24, 75, 64, 91
 * */
