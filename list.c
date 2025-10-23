#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * Returns the tail (last node) of the linked list
 * 
 * @param head pointer to the first node of the linked liat 
 * @return Pointer to last node, or null if list is empty
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL)
        return NULL;

    struct ll_node *node = head;
    while (node->next != NULL)
        node = node->next;
    return node;
}

/**
 * Returns the number of nodes in the linked list.
 *
 * @param head Pointer to the first node of the linked list.
 * @return The total number of nodes in the list.
 */
int ll_size(struct ll_node *head) {
   int count = 0;
    struct ll_node *node = head;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

/**
 * Searches the linked list for a node containing a specific value.
 *
 * @param head Pointer to the first node of the linked list.
 * @param value The value to search for in the list.
 * @return Pointer to the node containing the value, or NULL if not found.
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
   struct ll_node *node = head;
    while (node != NULL) {
        if (node->data == value)
            return node;
        node = node->next;
    }
    return NULL;
}

/**
 * Converts the linked list into a dynamically allocated array.
 *
 * @param head Pointer to the first node of the linked list.
 * @return Pointer to a newly allocated array containing the list’s values,
 *         or NULL if the list is empty or allocation fails.
 */
int *ll_toarray(struct ll_node *head) {
   int size = ll_size(head);
    if (size == 0)
        return NULL;

    int *arr = malloc(size * sizeof(int));
    if (arr == NULL)
        return NULL;

    struct ll_node *node = head;
    for (int i = 0; i < size; i++) {
        arr[i] = node->data;
        node = node->next;
    }
    return arr;
}

/**
 * Creates a new linked list node with the specified data.
 *
 * @param data The integer value to store in the new node.
 * @return Pointer to the newly created node, or NULL if allocation fails.
 */
struct ll_node *ll_create(int data) {
   struct ll_node *node = malloc(sizeof(struct ll_node));
    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * Frees all nodes in the linked list.
 *
 * @param head Pointer to the first node of the linked list.
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *node = head;
    while (node != NULL) {
        struct ll_node *next = node->next;
        free(node);
        node = next;
    }
}

/**
 * Appends a new node with the specified data to the end of the list.
 *
 * @param head Pointer to the first node of the linked list.
 * @param data The integer value to append to the list.
 */
void ll_append(struct ll_node *head, int data) {
  if (head == NULL)
        return;
    struct ll_node *tail = ll_tail(head);
    struct ll_node *new_node = ll_create(data);
    if (new_node == NULL)
        return;
    tail->next = new_node;
}

/**
 * Creates a linked list from an array of integers.
 *
 * @param data Pointer to the array of integers.
 * @param len The number of elements in the array.
 * @return Pointer to the head of the newly created linked list,
 *         or NULL if the array is empty or allocation fails.
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if (data == NULL || len <= 0)
        return NULL;
    struct ll_node *head = ll_create(data[0]);
    if (head == NULL)
        return NULL;
    struct ll_node *tail = head;
    for (int i = 1; i < len; i++) {
        struct ll_node *new_node = ll_create(data[i]);
        if (new_node == NULL)
            break;
        tail->next = new_node;
        tail = new_node;
    }
    return head;
}

/**
 * Removes the first node in the list containing the specified value.
 *
 * @param head Pointer to the first node of the linked list.
 * @param value The value of the node to remove.
 * @return Pointer to the (possibly new) head of the list.
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if (head == NULL)
        return NULL;
    if (head->data == value) {
        struct ll_node *next = head->next;
        free(head);
        return next;
    }
    struct ll_node *prev = head;
    struct ll_node *curr = head->next;
    while (curr != NULL) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

