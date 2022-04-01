#include <stdio.h>
#include <stdlib.h>

#define BODY_TYPE_LENGTH 20
// Struct
typedef struct
{
  double milage;
  int year;
  char *color;
  double horsePower;
  char bodyType[BODY_TYPE_LENGTH]; // ie SUV, Truck etc.
} car_t;

void printCar(car_t);
void addMilageToCar(car_t*, double);

/*
Also:
struct car_t { ... }
But then in code you must do struct car_t name...
*/

// Functions using structs

int main()
{
  car_t firstCar;
  printf("What year is the car?\n");
  scanf("%d",&firstCar.year);
  firstCar.color = "Red";
  firstCar.bodyType[0] = 'S';
  firstCar.bodyType[1] = 'U';
  firstCar.bodyType[2] = 'V';
  firstCar.bodyType[3] = '\0';
  firstCar.milage = 60000;
  firstCar.horsePower = 250;
  printCar(firstCar);
  addMilageToCar(&firstCar, 1000);
  printf("\n");
  printCar(firstCar);
  return 0;
}

void printCar(car_t car) {
  printf("Color: %s\n", car.color);
  printf("Year: %d\n", car.year);
  printf("Body Type: %s\n", car.bodyType);
  printf("Milage: %lf\n", car.milage);
  printf("HP: %lf\n", car.horsePower);
}

void addMilageToCar(car_t* car, double newMilage) {
  printf("Would you like to reset the miles\n");
  scanf("%lf", &car->milage); // &(*car).milage
  car->milage += newMilage; // (*car).milage
}