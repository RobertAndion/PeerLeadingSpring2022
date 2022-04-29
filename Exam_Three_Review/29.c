#include <stdio.h>
#include <stdlib.h>

struct node
{
  int value;
  struct node *next;
};
struct node *move_first_to_last(struct node *);

struct node *move_first_to_last(struct node *list)
{
  /*
  Empty list
  One node list
  First and last -- Normal case
  */
  if (list == NULL) // Empty
    return list;
  if (list->next == NULL) // One node
    return list;
  // From this point we have at least 2 nodes and they need to be swapped.
  struct node *tail = list;
  while (tail->next != NULL) // Go until cur == End of list
    tail = tail->next;
  // for(tail = list; tail->next != NULL; tail = tail->next);

  struct node *oldHead = list;
  tail->next = oldHead;
  list = list->next; // Move head to second node
  oldHead->next = NULL;

  return list;
}

int main()
{
  // Bad practice to do this but we dont have time for an insert function.
  struct node *head = malloc(sizeof(struct node));
  head->value = 10;
  head->next = malloc(sizeof(struct node));
  head->next->value = 25;
  head->next->next = malloc(sizeof(struct node));
  head->next->next->value = 250;
  head->next->next->next = NULL;

  struct node *temp = head;
  while (temp != NULL)
  {
    printf("Value: %d\n", temp->value);
    temp = temp->next;
  }

  head = move_first_to_last(head);
  temp = head;
  printf("#######\n");
  while (temp != NULL)
  {
    printf("Value: %d\n", temp->value);
    temp = temp->next;
  }

  return 0;
}