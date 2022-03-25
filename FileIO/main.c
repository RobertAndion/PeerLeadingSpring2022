#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500
#define DEFAULT_FILE "data.txt"

int main(int argc, char *argv[])
{
  // fp
  FILE *fp;

  // Default filename if no cli input, otherwise given name is used.
  if (argc < 2)
  {
    fp = fopen(DEFAULT_FILE, "r");
  }
  else
  {
    fp = fopen(argv[1], "r");
  }

  // Ensure file exists and was oppened correctly.
  if (fp == NULL)
  {
    printf("File does not exist.\n");
    exit(-1);
  }
  char buffer[MAX_SIZE];

  // fgets
  while (fgets(buffer, MAX_SIZE, fp))
  {
    printf("%s", buffer); // Each line: "Project1 A 95\n"
  }
  printf("\n");

  // fscanf
  // Reset the file back to the beginning.
  rewind(fp);

  char firstEntry[MAX_SIZE], secondEntry[MAX_SIZE], thirdEntry[MAX_SIZE];
  int fReturn;
  while (1)
  {
    fReturn = fscanf(fp, "%s %s %s", firstEntry, secondEntry, thirdEntry);
    if (fReturn == EOF) {
      break;
    }
    if (fReturn < 3) {
      printf("Malformatted file.\n");
      exit(-1);
    }
    printf("%s %s %s\n", firstEntry, secondEntry, thirdEntry);
  }

  fclose(fp);
}
