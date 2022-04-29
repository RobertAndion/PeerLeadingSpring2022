#include "linkedlist.h"

// Return a newly generated and configured Linked List pointer
linked_list_t *intitialize()
{
  linked_list_t *ret = malloc(sizeof(linked_list_t));
  if (ret == NULL)
    return NULL;
  ret->head = ret->tail = NULL;
  ret->size = 0;
  return ret;
}
/*
// Push Back
void push_back(linked_list_t *LL, DATA_TYPE data)
{
  struct node_t *temp = create_node(data);
  temp->prev = LL->tail;
  LL->size++;
  if (LL->tail == NULL)
  {
    LL->tail = LL->head = temp;
  }
  else
  {
    LL->tail->next = temp;
    LL->tail = temp;
  }
}

// Push Front
void push_front(linked_list_t *LL, DATA_TYPE data)
{
  struct node_t *temp = create_node(data);
  temp->next = LL->head;
  LL->size++;
  if (LL->head == NULL)
  {
    LL->head = LL->tail = temp;
  }
  else
  {
    temp->next = LL->head;
    LL->head->prev = temp;
    LL->head = temp;
  }
}
*/
// Search
struct node_t *search_list(linked_list_t *LL, DATA_TYPE data)
{
  struct node_t *temp = LL->head;
  if (temp == NULL)
    return NULL;
  for (; temp != NULL; temp = temp->next)
  {
    if (temp->data == data)
      return temp;
  }
  return NULL;
}

// Insert function, keep an ordered list.
void insert(linked_list_t *LL, DATA_TYPE value)
{
  struct node_t *temp = LL->head;
  struct node_t *new_node = create_node(value);
  LL->size++;
  /* 
  Search for proper spot, a few cases.
  1. Empty List
  2. Insert at head
  3. Insert at tail
  4. Insert in the middle
  */
 if (temp == NULL) {
   LL->head = LL->tail = new_node;
   return;
 }
  while (temp->next != NULL) { // Head, Middle
    if (temp->data > new_node->data) {
      if (temp == LL->head) {
        LL->head = new_node;
        temp->prev = new_node;
        new_node->next = temp;
        return;
      } else { // In the middle of two nodes.
        // We must insert new_node before temp
        struct node_t *next = temp;
        struct node_t *prev = temp->prev;

        new_node->next = temp;
        new_node->prev = prev;

        prev->next = new_node;
        next->prev = new_node;
        return;
      }
    }
    temp = temp->next;
  }
  // If we make it outside the while loop it is the tail case.
  if (temp->data > new_node->data) { // before tail
    struct node_t * tail = LL->tail;
    struct node_t * prev = LL->tail->prev;
    
    new_node->next = tail;
    new_node->prev = prev;
    prev->next = new_node;
    tail->prev = new_node;

  } else { // new tail
    LL->tail->next = new_node;
    new_node->prev = LL->tail;
    LL->tail = new_node;
  }
}

void delete_node(linked_list_t *LL, DATA_TYPE value) // finish
{                                                    // To be continued
  struct node_t *temp = search_list(LL, value);
  if (temp == NULL)
  {
    printf("Error, node not found!\n");
    return;
  }
  // [*]
  // [] [*] []
  // [*] [] []
  // [] [] [*]
  if (temp == LL->head && temp == LL->tail) // One node list
  {
    LL->head = LL->tail = NULL;
  }
  else if (temp == LL->head) // Node is head, at least 2 nodes.
  {
    LL->head = temp->next;
    temp->next->prev = NULL;
  }
  else if (temp == LL->tail) // Node is tail, at least 2 nodes
  {
    LL->tail = temp->prev;
    temp->prev->next = NULL;
  }
  else // In the middle of two nodes.
  {
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
  }
  LL->size--;
  free(temp);
}

struct node_t *create_node(DATA_TYPE data)
{
  struct node_t *temp = malloc(sizeof(struct node_t));
  temp->data = data;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}

void print_list(linked_list_t *LL)
{
  struct node_t *temp = LL->head;
  if (temp == NULL)
    return;
  for (; temp != NULL; temp = temp->next)
    printf("%d\n", temp->data);
}

void print_list_reverse(linked_list_t *LL)
{
  struct node_t *temp = LL->tail;
  if (temp == NULL)
    return;
  for (; temp != NULL; temp = temp->prev)
    printf("%d\n", temp->data);
}
