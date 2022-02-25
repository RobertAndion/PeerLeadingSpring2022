#include <stdio.h>

#define ARRAY_SIZE 10

int main()
{
    int x = 10, y = 7, z = 45, r = 100;
    // Similar: array name is a pointer, 
    int normalArray[ARRAY_SIZE]; // Each element is an actual integer

    int *pointerArray[ARRAY_SIZE]; // Each element is a new int pointer

    normalArray[0] = x; // Shallow copy
    pointerArray[0] = &x;
    pointerArray[1] = &y;
    *pointerArray[0] = 15;
    int *p = normalArray + 3;
    *p = 25;
    printf("Normal Array[3]: %d\n", *(normalArray + 3)); // *(normalArray + 3) == normalArray[3]
    printf("Pointer Array[0]: %d\n", **pointerArray); // *normalArray == normalArray[0], *pointerArray[0]
    // pointerArray[0] -> &P -> &x -> x
    printf("X: %d\n", x);

    return 0;
}