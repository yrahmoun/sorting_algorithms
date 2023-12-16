#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list
 * @list: pointer to double linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list;
	listint_t *prev;
	listint_t *next;

	if (!list || !*list || (*list)->next == NULL)
		return;
	while (curr)
	{
		while (curr->prev && curr->prev->n > curr->n)
		{
			prev = curr->prev;
			next = curr->next;
			if (prev->prev)
				prev->prev->next = curr;
			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;
			prev->next = next;
			if (next)
				next->prev = prev;
			if (!curr->prev)
				*list = curr;
			print_list(*list);
		}
		curr = curr->next;
	}
}

