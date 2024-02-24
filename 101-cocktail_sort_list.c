#include "sort.h"

/**
 * swap_next - Swaps two adjacent nodes in the doubly linked list
 * @list: Pointer to the head of the list
 *
 * Return: Pointer to the new head of the potentially modified list segment
 */
listint_t *swap_next(listint_t **list) {
	listint_t *temp, *head = *list;

	if (!head || !head->next)
		return head;

	temp = head->next;

	if (head->prev)
		head->prev->next = temp;
	if (temp->next)
		temp->next->prev = head;

	temp->prev = head->prev;
	head->next = temp->next;
	head->prev = temp;
	temp->next = head;

	if (temp->prev == NULL)
		*list = temp;

	return temp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list) {
	int swapped = 1;
	listint_t *start, *end;

	if (!list || !*list)
		return;

	start = *list;
	end = NULL;

	while (swapped) {
		swapped = 0;

		/* Forward pass */
		while (start->next != end) {
			if (start->n > start->next->n) {
				start = swap_next(&start);
				swapped = 1;
				print_list(*list);
			} else {
				start = start->next;
			}
		}

		end = start;
		start = start->prev;

		/* Backward pass */
		while (start->prev != NULL) {
			if (start->n < start->prev->n) {
				start = swap_next(&start->prev);
				swapped = 1;
				print_list(*list);
			} else {
				start = start->prev;
			}
		}
	}
}