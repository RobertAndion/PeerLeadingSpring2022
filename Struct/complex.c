#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "data.txt"
#define MAX_STRING_SIZE 200

typedef struct
{
  int year;
  char make[MAX_STRING_SIZE];
  char model[MAX_STRING_SIZE];
  char color[MAX_STRING_SIZE];
  double milage;
} car_t;

void printCarCollection(car_t *, int);
double averageVehicleYear(car_t *, int);
// void * mystery(void *);

int main()
{
  FILE *fp = fopen(FILE_NAME, "r");
  int rows, cols;
  int i = 0;
  int year;
  double milage;
  /*
  int x = 25;
  void * test = (void *) &x;
  void * ret = mystery(test);
  printf("%d\n", *((int *) test));
  */

  char make[MAX_STRING_SIZE], model[MAX_STRING_SIZE], color[MAX_STRING_SIZE];
  fscanf(fp, "%d\t%d", &rows, &cols);
  car_t carCollection[rows];

  while (fscanf(fp, "%d\t%s\t%s\t%s\t%lf", &year, make, model, color, &milage) == cols)
  {
    carCollection[i].year = year;
    strcpy(carCollection[i].make, make);
    strcpy(carCollection[i].model, model);
    strcpy(carCollection[i].color, color);
    carCollection[i].milage = milage;
    ++i;
  }

  fclose(fp);
  printCarCollection(carCollection, rows);
  printf("%.2lf\n", averageVehicleYear(carCollection, rows));
}

void printCarCollection(car_t *carCollection, int rows)
{
  int i;
  for (i = 0; i < rows; i++)
  {
    printf("%d\t%s\t%s\t%s\t%lf\n", carCollection[i].year, carCollection[i].make, carCollection[i].model, carCollection[i].color, carCollection[i].milage);
  }
}

double averageVehicleYear(car_t * carCollection, int rows) {
  int i;
  double sum;
  for(i = 0; i < rows; ++i) {
    sum += carCollection[i].year;
  }
  return sum / (double) rows;
}
/*
void * mystery(void * arg) {
  int * x = (int *) arg;
  printf("%d", *x);
  return NULL;
}
*/