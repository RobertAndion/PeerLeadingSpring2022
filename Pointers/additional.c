#include <stdio.h>
int buildCone(int *, double *);
void findTwoLargest(int *, int *, int *, int n);

int main() {
    int icecreamCones = 10;
    double vanillaIcecream = 2.5;
    double pricePerCone = 2.55;
    // iPointer == &icecreamCones;
    int * iPointer = &icecreamCones; // Optional
    double *vPointer = &vanillaIcecream;
    int result = buildCone(&icecreamCones, vPointer);
    if (result) {
        printf("Heres your cone!\n");
        printf("Inventory: %d, %lf", icecreamCones, vanillaIcecream);
    } else {
        printf("We are out of icecream :(\n");
    }
    int arr[] = {25,250,2000,12,1,78};
    int biggest;
    int secondBiggest;
    int n = 6;
    findTwoLargest(arr, &biggest, &secondBiggest, n);
    printf("\nBiggest: %d SecondBiggest: %d\n", biggest, secondBiggest);

    /* Double Pointers
    int data = 10;
    int * p = &data;
    int ** d = &p;
    printf("%p %p %d\n", d, *d, **d);
    printf("%p %d\n", p, *p);
    */
}

int buildCone(int * cones, double * icecream) {
    if (*cones > 1 && *icecream > 0.5) {
        (*cones)--; // *cones-- -> Meant the address was getting -- then dereferenced
        *icecream -= 0.5;
        return 1;
    } else {
        return 0;
    }
}

void findTwoLargest(int *arr, int * retOne, int * retTwo, int n) {
    int * p = arr;
    int * largest = p;
    for(;p < arr + n; ++p) {
        if (*largest < *p) {
            largest = p;
        }
    }
    *retOne = *largest; // retOne now has the address of the largest element
    
    int * temp = largest;
    if (arr != retOne) {
        largest = arr + 1;
        p = arr + 1;
    } else {
        largest = arr;
        p = arr;
    }

    for(;p < arr + n; ++p) {
        if (*largest < *p && p != temp) {
            largest = p;
        }
    }
    *retTwo = *largest;
}