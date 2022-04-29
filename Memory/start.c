#include <stdio.h>
#include <stdlib.h>

typedef int DATA_TYPE; // Same as define DATA_TYPE int

typedef struct {
  DATA_TYPE data;
  node_t * next;
  // node_t * prev; Used for doubly linked list
} node_t;

typedef struct {
  node_t * head;
  // node_t * mid; Useful but hard to keep track of
  // node_t * tail; Used for doubly linked list
  unsigned int size;
} linked_list_t;

int * generateIntArray(int);

int main() {
  int x = 10;
  int * y = malloc(sizeof(int));
  if (y == NULL) {
    printf("Program ran out of memory!\n");
    exit(-1);
  }

  *y = 100;
  printf("%d\n", *y);
  free(y);

  printf("%d\n", *y);
  y = malloc(sizeof(int));
  free(y);
  y = generateIntArray(10); // Same as: y = malloc(sizeof(int) * 10)
  if (y == NULL)
    exit(-1);

  for(int i = 0; i < 10; ++i) {
    y[i] = i;
  }
    for(int i = 0; i < 10; ++i) {
      if (i != 9)
        printf("%d, ",y[i]);
      else 
        printf("%d", y[i]);
  }
  printf("\n");

  // Malloc with structures linked_list_t and node_t !!

  linked_list_t * firstList = malloc(sizeof(linked_list_t));
  firstList->head = malloc(sizeof(node_t));
  firstList->head->data = 10;
  /*
  Linked list visualization (Note [] are nodes and they are not actually in a line in memory but randomly placed and tied together with -> (pointers))
          LL
          |
   Head: []->[]->[]->[]->[]->[]->NULL : Tail
  NULL <-  <-  <-  <-  <-  <-  <-
  [, , , , , , , ] // Normal array, contiguous in memory
  */
}

int * generateIntArray(int size) {
  return malloc(sizeof(int) * size);
}
// Both cause dangling pointers.
/*
int * simpleExample(int x) {
  int y = x;
  return &y; // Value of y, not y
} // End of function, y is deleted.

int * example(int * array) {
  // code to copy array
  int newArray[50];
  return newArray;
}
*/


