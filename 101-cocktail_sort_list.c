#include "sort.h"

/*
listint_t prev_swap(listint_t *node1, listint_t *node2)
{
	return NULL;
}
*/
/**
 * cocktail_sort_list - implement cocktail shaker sort
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	int flag = 0, loop_prev = 0, loop_next = 1;
	listint_t *loop1 = *list, *head = *list, *tmp;

	if (!head || !(head->next))
		return;

	while (loop1)
	{
		if (loop_next && loop1->next && loop1->n > loop1->next->n)
		{
			flag = 1;
			tmp = loop1->next;
			if (loop1->prev)
				loop1->prev->next = tmp;
			if (tmp->next)
				tmp->next->prev = loop1;
			loop1->next = tmp->next;
			tmp->prev = loop1->prev;
			tmp->next = loop1;
			loop1->prev = tmp;
			if (tmp->prev == NULL)
				head = tmp->prev;
			print_list(head);
		}

		if (loop_prev && loop1->prev && loop1->n < loop1->prev->n)
		{
			flag = 1;
			tmp = loop1->prev;
			if (tmp->prev)
				tmp->prev->next = loop1;
			if (loop1->next)
				loop1->next->prev = tmp;
			loop1->prev = tmp->prev;
			tmp->next = loop1->next;
			tmp->prev = loop1;
			loop1->next = tmp;
			if (loop1->prev == NULL)
				head = loop1;
			print_list(head);
		}

		if (flag && loop1->next == NULL)
		{
			flag = 0;
			loop_prev = 1;
			loop_next = 0;
		}

		if (flag && loop1->prev == NULL)
		{
			flag = 0;
			loop_prev = 0;
			loop_next = 1;
		}

		if (loop_next)
			loop1 = loop1->next;
		if (loop_prev)
			loop1 = loop1->prev;
	}
	*list = head;
}
