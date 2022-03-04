#include <stdio.h>
#define MAX_ARRAY 11
/*
Purpose: Create a fuction capable and competent at reading strings until the end of line.
TODO:
    1. Store input including whitespace into an array
    2. Stop when the array is full
    3. Optional: Skip leading whitespace (Parameter)
    4. Add a null character at the end
    5. Stop when we reach '\n'
    6. Args: We need an array, we need a max size
*/
// readLine(arr, MAX_ARRAY - 1);
// readLine(arr, MAX_ARRAY); I prefer this call
int readLine(char *arr, int maxSize);

int main()
{
    // Test No input
    // Test small input
    // Test max input
    // Test overflow
    char test[MAX_ARRAY];
    readLine(test, MAX_ARRAY);
    printf("%s\n", test);
}

// A function to read in a line of user input safetly, no overflow is possible.
int readLine(char *arr, int maxSize)
{
    int len = 0;
    char ch;
    while ((ch = getchar()) != '\n' && len < (maxSize - 1))
    {
        arr[len] = ch;
        ++len;
    }
    arr[len] = '\0';
    return len;
}
