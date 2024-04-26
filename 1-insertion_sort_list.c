#include "sort.h"

/**
 * swap_nodes - Swap two consecutive nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: A pointer to the second node to swap.
 *
 * Assumes n1 and n2 are consecutive and n1 is before n2.
 */
void swap_nodes(listint_t **h, listint_t *n1, listint_t *n2)
{
    if (n1->prev) 
        n1->prev->next = n2;
    if (n2->next)
        n2->next->prev = n1;

    n2->prev = n1->prev;
    n1->prev = n2;
    n1->next = n2->next;
    n2->next = n1;

    if (!n2->prev) 
        *h = n2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *iter = (*list)->next;

    while (iter != NULL)
    {
        while (iter->prev != NULL && iter->n < iter->prev->n)
        {
            swap_nodes(list, iter->prev, iter);
            print_list((const listint_t *)*list);
        }
        iter = iter->next;
    }
}
