#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail Shaker sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list) {
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	swapped = 1;
	while (swapped) {
		swapped = 0;

		/* Forward iteration (bubble sort) */
		for (current = *list; current->next != NULL; current = current->next) {
			if (current->n > current->next->n) {
				/* Swap nodes */
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;

				if (current->next->next != NULL)
					current->next->next->prev = current;

				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;
				current->prev->next = current;

				swapped = 1;
				print_list(*list);
			}
		}

		/* Check if no swap occurred */
		if (!swapped)
			break;

		swapped = 0;

		/* Backward iteration (bubble sort) */
		for (; current->prev != NULL; current = current->prev) {
			if (current->prev->n > current->n) {
				/* Swap nodes */
				if (current->next != NULL)
					current->next->prev = current->prev;

				current->prev->next = current->next;
				current->next = current->prev;
				current->prev = current->prev->prev;

				if (current->prev != NULL)
					current->prev->next = current;
				else
					*list = current;

				swapped = 1;
				print_list(*list);
			}
		}
	}
}