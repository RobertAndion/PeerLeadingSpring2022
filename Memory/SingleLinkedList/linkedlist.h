#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __cereal_
{
  char *name;
  int calories;
  double length, width, height;
} cereal;

typedef cereal DATA_TYPE;

struct node_t
{
  cereal *data;
  struct node_t *next;
};

typedef struct
{
  struct node_t *head;
  unsigned int size;
} linked_list_t;

linked_list_t *intitialize();
struct node_t *create_node(char *, int, double, double, double);
void insert(linked_list_t *, char *, int, double, double, double);
struct node_t *search_list(linked_list_t *, char *, int, double, double, double);
void delete_node(linked_list_t *, char *, int, double, double, double);
void print_list(linked_list_t *);

#endif