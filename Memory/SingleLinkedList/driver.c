#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main()
{
  linked_list_t *LL = intitialize();
  insert(LL, "Frosted Flakes", 150, 12, 4, 20);
  insert(LL, "Pops", 150, 12, 4, 20);
  insert(LL, "Cinnamon Toast Crunch", 150, 12, 4, 20);
  insert(LL, "Cinnamon Toast Crunch", 155, 12, 4, 20);
  print_list(LL);
  delete_node(LL, "Cinnamon Toast Crunch", 155, 12, 4, 20);
  printf("\n\n");
  print_list(LL);
  printf("size: %d\n", LL->size);
  return 0;
}