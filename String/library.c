#include <stdio.h>
#include <string.h>

int main() {
    char *p = "Hello";
    char *q = "Hello";
    char *w = "Bye";
    printf("Length of string p: %d\n",strlen(p));
    
    // printf("%d", 'a' - 'z');
    /*
    Character by character p - q
    If the result is 0 they are the same
    If the result is negative p is first
    If the result is positive q is first
    */

    if (strcmp(p,q) < 0) {
        printf("First string is first\n");
    } else if (strcmp(p,q) > 0) {
        printf("Second string is first\n");
    } else if (strcmp(p,q) == 0) {
        printf("They are the same string.\n");
    }

    if (strcmp(p,q) == 0) { // Equal

    } else { // Not equal

    }

    char stringOne[12] = "Hello ";
    
    for(int i = 0; i < strlen(stringOne); ++i) {
        printf("%c",stringOne[i]);
    }
    printf("\n");

    char stringTwo[] = "There";
    strcat(stringOne,stringTwo);
    printf("%s\n",stringOne);

    char stringNumber[] = "123Z45!";
    for (int i = 0; i < strlen(stringNumber); ++i) {
        if (!(stringNumber[i] > '9' || stringNumber[i] < '0')) {
            printf("%d\n",stringNumber[i] - '0');
        } else {
            printf("%c is not a number.\n",stringNumber[i]);
        }
    }
    
}