#include "read_line.h"

int readLine(char *arr, int maxSize)
{
  int len = 0;
  char ch;
  while ((ch = getchar()) != '\n' && len < (maxSize - END_OF_BUFFER_PADDING))
  {
    arr[len] = ch;
    ++len;
  }
  arr[len] = '\0';
  return len;
}