#include "sort.h"

/**
 * insertion_sort_list - implementing inertion sort algorithm
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *loop1 = *list, /*loop2,*/ *tmp;
	int flag = 1;

	if (!(*list) || !(*list)->next)
		return;

	while (loop1)
	{
		if (loop1->n > loop1->next->n)
		{
			flag = 0;
			tmp = loop1->next;
			tmp->prev = loop1->prev;
			loop1->next = tmp->next;
			loop1->prev = tmp;
			loop1 = tmp;
		}
		if (flag)
			loop1 = loop1->next;
		flag = 1;
	}
}
