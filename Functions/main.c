#include <stdio.h>

void printArray(int[], int);
void sortArray(int[], int);

int main()
{
    int length = 7;
    int integerArray[] = {12, 15, 65, 87, 4, 5, 1};
    sortArray(integerArray, length);
    // printArray(integerArray, length); // Function call with arguments

    return 0;
}

void printArray(int array[], int size)
{ // Print function, function paramaters
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d\n", array[i]);
    }
}

void sortArray(int array[], int size)
{
    int i, j;
    for (i = 0; i < size; ++i) // i++/++i == i = i + 1
    {
        for (j = i + 1; j < size; ++j)
        {
            if (array[i] > array[j]) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    printArray(array, size);
}