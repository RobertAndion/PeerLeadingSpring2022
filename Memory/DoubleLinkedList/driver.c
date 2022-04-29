#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main() {
  linked_list_t * LL = intitialize();
  /*print_list(LL);
  push_front(LL, 500);
  int i;
  for(i = 0; i < 10; ++i)
    push_back(LL, i);
  push_front(LL, 1000);

  print_list(LL);
  print_list_reverse(LL);

  struct node_t * result = search_list(LL, 0);
  if (result == NULL) {
    printf("Failed to find!\n");
  } else {
    printf("Found: %d at %p\n", result->data, result);
  } */
  insert(LL,0);
  insert(LL, -1);
  print_list(LL);
  return 0;
}