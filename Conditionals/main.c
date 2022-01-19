#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define BOOL int

int main() {
    // Switch
    int userSelection;
    printf("Enter a number between 1 and 4: ");
    scanf("%d",&userSelection);

    // I want to print what number they selected.
    // printf("You selected: %d\n",userSelection); Easy method

    switch (userSelection) {
        case 1:
            printf("You selected 1\n");
            break;
        case 2:
            printf("You selected 2\n");
            break;
        case 3:
            printf("You selected 3\n");
            break;
        case 4:
            printf("You selected 4\n");
            break;
        default:
            printf("Please try again.\n");
    }

    // if else
    printf("Enter 1-4 to continue, enter anything else to exit: ");
    scanf("%d",&userSelection);

    while(1) {
        if(userSelection == 1) {
            printf("You selected 1\n");
        } else if (userSelection == 2) {
            printf("You selected 2\n");
        } else if (userSelection == 3) {
            printf("You selected 3\n");
        } else if (userSelection == 4) {
            printf("You selected 4\n");
        } else {
            printf("Thank you for using our application.\n");
            break;
        }
        printf("Please enter your next selection: ");
        scanf("%d",&userSelection);
    }

    /*
    if(userSelection == 1) {
        printf("You selected 1\n");
    }

    if(userSelection == 2) {
        printf("You selected 2\n");
    }
    */

    // booleans
    int booleanTrue = 1;
    int booleanFalse = 0;

    BOOL macroValueExample = TRUE;

    if (booleanTrue) {
        printf("True\n");
    }

    if (booleanFalse) {
        printf("False\n");
    }

    // logical operators

    // && This means both sides must be true
    // || This means either side can be true

    if ((1 && 0) || 1) {
        printf("I was true\n");
    }

    return 0;
}