#include <stdio.h>

#define ARRAY_SIZE 51

int main()
{
    // String literals
    char * p = "This is a string"; // "" For strings, '' For characters
    char * q = "Hi!";
    // "String" (Character) Arrays
    char example[] = "This is a string";
    int arr[ARRAY_SIZE]; // {1 , 2, 3, 4 ...}
    char firstString[ARRAY_SIZE]; // firstString[0] = 'a'... => {'a', 'b', 'c', ...}
    firstString[0] = 'H';
    firstString[1] = 'i';
    firstString[2] = '!';
    firstString[3] = '\0';

    char secondString[ARRAY_SIZE];

    // IO of strings

    // Character by character
    char * iter = example;
    for(; *iter !='\0'; iter++)
        printf("%c",*iter);
    printf("\n");

    printf("%s\n", p);
    printf("%s\n", firstString);
    printf("Please enter a line of text less than 50 characters.\n");
    scanf("%s", secondString); // spaces and too long input break this. Very unsafe, not recommended. --> See readline.c
    printf("%s\n", secondString);

}