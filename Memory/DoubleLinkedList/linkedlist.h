#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

#include <stdio.h>
#include <stdlib.h>

typedef int DATA_TYPE;

struct node_t
{
  DATA_TYPE data;
  struct node_t *next;
  struct node_t *prev;
};

typedef struct
{
  struct node_t *head;
  struct node_t *tail;
  unsigned int size;
} linked_list_t;

linked_list_t *intitialize();
struct node_t *create_node(DATA_TYPE);
// void push_back(linked_list_t *, DATA_TYPE);
// void push_front(linked_list_t *, DATA_TYPE);
void insert(linked_list_t *, DATA_TYPE);
struct node_t * search_list(linked_list_t *, DATA_TYPE);
void delete_node(linked_list_t *, DATA_TYPE);
void print_list(linked_list_t *);
void print_list_reverse(linked_list_t *LL);

#endif