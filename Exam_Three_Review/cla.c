#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;
  if (argc == 1)
  {
    printf("Please enter your name!\n");
    return -1;
  }
  for (i = 1; i < argc; ++i)
  {
    printf("%s\n", argv[i]);
  }
  printf("####\n");
  for (i = argc - 1; i > 0; --i) // argc - 1 to stay in range (i.e. array starts at 0 not 1), do not print index 0 that is the program name.
  {
    printf("%s\n", argv[i]);
  }
  return 0;
}