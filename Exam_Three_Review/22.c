#include <stdio.h>
#include <stdlib.h>

int count_characters(const char *);
//void * test();

int main()
{
  printf("%d\n", count_characters("test.txt"));
  /*void* ret = test();
  printf("%d\n", *(int *)ret);
  int * secondTime = (int *) test();
  printf("%d\n", *secondTime);
  */
  return 0;
}

int count_characters(const char *filename)
{                 // Open the file, count the number of characters
  char str[1001]; // 30 should be our answer.
  FILE *pFile;
  int count = 0;

  pFile = fopen(filename, "r");
  if (pFile == NULL)
    return 0;

  while (fgets(str, 1001, pFile))
  {
    char *p = str;
    while (*p != '\0')
    {
      if (*p != '\n')
      {
        count++;
      }
      p++;
    }
  }
  return count;
}

/* Memory Leak Example */
void memory_leak() {
  int *p = malloc(sizeof(int));
  int x = 10;
  free(p);
  p = &x;
}
/* Void Pointer Example*/
void * test() {
  int * new = malloc(sizeof(int));
  *new = 10;
  return (void *) new;
}
