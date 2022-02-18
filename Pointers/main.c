#include <stdio.h>

void swapVariablesOldWay(int *, int *);
void swapVariablesNewWay(int *, int *);
void printArray(int *, int);

int main()
{ // Basic pointer assignment and usage
    int baseValue = 10;
    int *basePointer = &baseValue;
    printf("%p : %d\n", basePointer, *basePointer);
    int first = 15, second = 25;
    // int *firstPointer = &first;
    printf("First and second before call: %d %d\n", first, second);
    swapVariablesOldWay(&first, &second);
    printf("First and second after call: %d %d\n", first, second);

    int third = 100, fourth = 200; // Declared but only ever used through pointers
    int *pThird = &third;
    int *pFourth = &fourth;
    printf("Third and Fourth before call: %d %d\n", *pThird, *pFourth);
    int *temp = pThird;
    pThird = pFourth;
    pFourth = temp;
    printf("Third and Fourth after call: %d %d\n", *pThird, *pFourth);
    printf("Original third and fourth: %d %d\n", third, fourth);

    int testArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 22, 33, 44, 55, 66, 77};
    int * testArrayPointer[10];
    int two = 20;
    testArrayPointer[0] = &two;
    printArray(testArray, 16);
}

void printArray(int *arr, int n)
{ // Print array using pointer arithmetic
    int * p;
    int i;
    for(i = 0, p = arr; i < n; i++, p++) {
        printf("%p %d\n", p, *p);

    }

    p = arr;
    p = p + 15; // 15 => 15 * (4)
    printf("%p %d\n", p, *p);
}

void swapVariablesOldWay(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/*
void swapVariablesNewWay(int *third, int *fourth)
{
    int *temp = third;
    third = fourth;
    fourth = temp;
}
*/