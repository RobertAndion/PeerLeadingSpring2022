#include <stdio.h>

int main () {
    // Pointer review
    int x = 0;
    int * p = &x;
    *p = 15;
    x = 25;
    printf("%p\n", p);
    printf("%d\n", *p);
    printf("%d\n", x);
    return 0;
}