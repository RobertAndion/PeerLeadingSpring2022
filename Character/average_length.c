// Read in a users input character by character and average all word lengths.
#include <stdio.h>
int main()
{
  char ch = getchar();
  int wordCount = 0;
  int sum = 0;
  int currentCharacterAmount = 0;

  while (ch != '\n')
  {
    if (ch == ' ')
    {
      if (currentCharacterAmount > 0)
      {
        sum += currentCharacterAmount;
        currentCharacterAmount = 0;
        wordCount++;
      }
      while ((ch = getchar()) == ' ')
        ;
    }
    else
    {
      if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
        currentCharacterAmount++;
      ch = getchar();
    }
  }

  if (currentCharacterAmount > 0)
  {
    sum += currentCharacterAmount;
    wordCount++;
  }

  if (wordCount > 0)
  {
    printf("Average word length: %.02lf\n", (double)sum / (double)wordCount);
  }
  else
  {
    printf("No words were given.\n");
  }
}