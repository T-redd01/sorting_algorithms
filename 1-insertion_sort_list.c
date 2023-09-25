#include "sort.h"

/**
 * insertion_sort_list - implementing inertion sort algorithm
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *loop1 = *list, *loop2, *tmp, *head = *list;

	if (!(*list) || !(*list)->next)
		return;

	while (loop1->next)
	{
		if (loop1->n > loop1->next->n)
		{
			loop2 = loop1->next;
			if (loop1->prev)
				loop1->prev->next = loop2;
			if (loop2->next)
				loop2->next->prev = loop1;
			loop2->prev = loop1->prev;
			loop1->next = loop2->next;
			loop1->prev = loop2;
			loop2->next = loop1;
			if (loop2->prev == NULL)
				head = loop2;
			print_list(head);
			while (loop2->prev && loop2->prev->n > loop2->n)
			{
				tmp = loop2->prev;
				if (tmp->prev)
					tmp->prev->next = loop2;
				if (loop2->next)
					loop2->next->prev = tmp;
				loop2->prev = tmp->prev;
				tmp->next = loop2->next;
				loop2->next = tmp;
				tmp->prev = loop2;
				if (loop2->prev == NULL)
					head = loop2;
				print_list(head);
			}
			continue;
		}
		loop1 = loop1->next;
	}
	*list = head;
}
