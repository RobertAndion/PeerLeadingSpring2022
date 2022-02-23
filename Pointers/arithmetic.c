#include <stdio.h>

int main()
{
    int collection[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Movement in array
    int *p = collection; // collection[0] *P == 1

    printf("%p\n",p);

    printf("%d\n", *p);
    p++;
    printf("%d\n", *p);
    p += 6;
    printf("%d\n", *p);
    p -= 7;
    printf("%d\n", *p);

    printf("########\n");

    // Address arithmetic

    int *q = collection, *r = (collection + 1);
    printf("%d\n", r - q);
    printf("%d %d\n", *r, *q);
    printf("%p %p\n", q, r);
    // 0x7fffcfad6150 : Base address == q
    // 0x7fffcfad6164 : Address of r 
    // r = 0x7fffcfad6150 + 5
    // r - q
    // 0x7fffcfad6150 + 5 - 0x7fffcfad6150
    // 5


    // Iterating through arrays with pointers

    // Tracking using an index
    int * iterator;
    int biggestIndex = 0;
    for (iterator = collection; iterator < collection + 10; iterator++) {
        // Looking for biggest value
        if (*iterator > *(collection + biggestIndex)) { // int * p = collection; p += biggestIndex; *p -- Equal
            biggestIndex = iterator - collection;
        }
    }
    printf("Biggest index: %d Biggest value: %d\n", biggestIndex, *(collection + biggestIndex)); // collection[biggestIndex]

    // Tracking using a pointer
    int * biggest = collection;

    for(iterator = collection; iterator < collection + 10; iterator++) {
        if (*iterator > *biggest) {
            biggest = iterator;
        }
    }
    printf("Biggest index: %d Biggest value: %d\n", biggest - collection, *biggest); // collection[biggestIndex]

    // collection[5];
    // p = p + 5;
    // address of collection + 5 * (element size) i.e. 4 for int

    return 0;
}