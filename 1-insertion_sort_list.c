#include "sort.h"

/**
 * swap - swaps two nodes in a double linked list
 * @list: pointer to double linked list
 * @prev: previous node
 * @curr: current node
 **/

void swap(listint_t **list, listint_t *prev, listint_t *curr)
{
	prev->next = curr->next;
	if (curr->next)
		curr->next->prev = prev;
	curr->prev = prev->prev;
	curr->next = prev;
	if (prev->prev)
		prev->prev->next = curr;
	else
		*list = curr;
	prev->prev = curr;
}

/**
 * insertion_sort_list - sorts a double linked list
 * @list: pointer to double linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list;

	if (!list || !*list || (*list)->next == NULL)
		return;
	curr = (*list)->next;
	while (curr)
	{
		while (curr->prev && curr->prev->n > curr->n)
		{
			swap(list, curr->prev, curr);
			print_list((const listint_t *)*list);
		}
		curr = curr->next;
	}
}
