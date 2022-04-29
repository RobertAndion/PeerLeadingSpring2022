#include "linkedlist.h"

// Return a newly generated and configured Linked List pointer
linked_list_t *intitialize()
{
  linked_list_t *ret = malloc(sizeof(linked_list_t));
  if (ret == NULL)
    return NULL;
  ret->head = NULL;
  ret->size = 0;
  return ret;
}

// Search
struct node_t *search_list(linked_list_t *LL, char *name, int calories, double length, double width, double height)
{
  struct node_t *temp = LL->head;
  if (temp == NULL)
    return NULL;
  for (; temp != NULL; temp = temp->next)
  {
    // Logic change
    if (strcmp(temp->data->name, name) != 0) // Names not equal case, most likely to fail so its first for speed.
      continue;
    if (temp->data->calories != calories)
      continue;
    if (temp->data->height != height)
      continue;
    if (temp->data->width != width)
      continue;
    if (temp->data->length != length)
      continue;
    return temp;
  }
  return NULL;
}

// Insert function, keep an ordered list.
void insert(linked_list_t *LL, char *name, int calories, double length, double width, double height)
{
  struct node_t *temp = LL->head;
  char *newString = malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(newString, name);
  struct node_t *new_node = create_node(newString, calories, length, width, height);
  LL->size++;
  struct node_t *current = LL->head, *previous = NULL;

  if (LL->head == NULL)
  {
    LL->head = new_node;
    return;
  }
  while (current != NULL)
  {
    if (strcmp(current->data->name, new_node->data->name) > 0)
    { // Should go after prev, before current.
      if (previous == NULL)
      { // We are the new head
        LL->head = new_node;
        new_node->next = current;
        return;
      }
      else
      {
        previous->next = new_node;
        new_node->next = current;
        return;
      }
    }
    previous = current;
    current = current->next;
  }
  // We will automatically be the tail at this point
  previous->next = new_node;
}

void delete_node(linked_list_t *LL, char *name, int calories, double length, double width, double height)
{                                                                                                         
  struct node_t *temp = search_list(LL, name, calories, length, width, height);
  if (temp == NULL)
  {
    printf("Error, node not found!\n");
    return;
  }

  struct node_t *current = LL->head, *previous = NULL;
  // [*]
  // [] [*] []
  // [*] [] []
  // [] [] [*]
  for (; current != temp; previous = current, current = current->next)
    ;
  if (current == LL->head)
  {
    LL->head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  LL->size--;
  free(current);
}

struct node_t *create_node(char *name, int calories, double length, double width, double height)
{
  struct node_t *temp = malloc(sizeof(struct node_t));
  temp->data = malloc(sizeof(DATA_TYPE));
  temp->data->name = name;
  temp->data->calories = calories;
  temp->data->length = length;
  temp->data->width = width;
  temp->data->height = height;
  temp->next = NULL;
  return temp;
}

void print_list(linked_list_t *LL)
{
  struct node_t *temp;

  if (temp == NULL)
    return;

  for (temp = LL->head; temp != NULL; temp = temp->next) {
    printf("###\n");
    printf("%s\n", temp->data->name);
    printf("%d\n", temp->data->calories);
    printf("%lf\n", temp->data->length);
    printf("%lf\n", temp->data->width);
    printf("%lf\n", temp->data->height);
    printf("###\n");
  }

}
