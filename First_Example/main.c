// Imports and Macros
#include <stdio.h>
#define MAX_NUMBER 100

// Main function
int main() {
    int num_apples_in_stock = 10; // Number of Apples
    int NumberOfApples = 10;
    int numApples = 10;
    int num = 10; // Worst naming convention
    int numApplesInStock = 10; // My prefered convention
    double applesTotal;
    double priceOfApple = 2.50;
    float priceOfAppleOnFriday = 1.50;
    int a,b,c;
    int e = 10,f,g = 2;
    // int a = e, b = e, c = e;
    // a = b = c = e;
    a = 100;
    b = 550;
    c = 10234;

    int numberOfApplesPurchased;

    printf("Please enter the amount of apples you bought: ");
    scanf("%d",&numberOfApplesPurchased);
    applesTotal = priceOfAppleOnFriday * numberOfApplesPurchased; 
    printf("Apple cost: %lf\n", applesTotal);
    printf("%5.5d\n%5.5d\n%5.5d\n", a, b, c);
    return 0;   
}

// Formatted Printing