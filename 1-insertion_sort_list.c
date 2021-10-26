#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: a doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cmp1 = NULL, *cmp2 = NULL, *aux = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	cmp1 = *list;
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
