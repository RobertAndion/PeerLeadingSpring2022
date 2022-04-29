#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

#define MAX_INPUT_LENGTH 500

int main()
{
  char buffer[MAX_INPUT_LENGTH];
  readLine(buffer,MAX_INPUT_LENGTH);
  printf("%s\n", buffer);
  return 0;
}
