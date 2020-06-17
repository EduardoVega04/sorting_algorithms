#include "sort.h"

/**
 * swap_nodes - Swaps two nodes
 * @node1: Pointer to address of node 1
 * @node2: Pointer to address of node 2
 * Return: Nothing
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{        
    listint_t *tmp = (*node1)->prev;
       
    (*node1)->next = (*node2)->next;
    
    if ((*node2)->next != NULL)
        (*node2)->next->prev = *node1;  

    (*node1)->prev = *node2;
    (*node2)->next = *node1;
    (*node2)->prev = tmp;

    if ((*node2)->prev != NULL)
        (*node2)->prev->next = *node2;
    else    
        *list = *node2;  
}

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion Sort
 * @list: Pointer to head of the linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{    
    listint_t *actual = NULL, *key = NULL, *spot = NULL;    

    if (*list == NULL || list == NULL)
        return;   

    for (actual = *list; actual != NULL; actual = actual->next)
    {
        while (actual->next != NULL && actual->n > actual->next->n)
        {
            key = actual->next;
            spot = actual;
            while (spot != NULL && spot->n > key->n)
            {
                swap_nodes(list, &spot, &key);
                print_list(*list);
                spot = key->prev;
            }
        }
    }                  
}
