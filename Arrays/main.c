#include <stdio.h>

#define MAX_ARRAY_SIZE 25

int main() {
    int integerArray[MAX_ARRAY_SIZE];
    int i;
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        integerArray[i] = (i + 1) * 10;
        // printf("%d\n", integerArray[i]);
    }
    
   for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d\n", integerArray[i]);
    }

    // Array types
    char charArray[MAX_ARRAY_SIZE]; // String?
    double doubleArray[MAX_ARRAY_SIZE];
    
    return 0;
}