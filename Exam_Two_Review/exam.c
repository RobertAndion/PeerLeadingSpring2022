#include <stdio.h>
/*
Order of requested Problems:

-- Madelaine --
17 - Solved in edge function - Done
20 - Solved in shift function - Done

-- Viraj --
5 - Solved in pdf
7 - Solved in pdf
11 - Solved in pdf
12 - Solved in pdf
13 - Solved in pdf
14 - Solved in pdf
19 - Solved in is_all_uppercase function - Done

-- End of Email Requests --

15 - Solved in split_time

*/
void edge(int *, int *, int);
void shift(char *, int);
int is_all_uppercase(char[]);
void split_time(int, int *, int *, int *);

int main()
{
    // Setup for edge
    int input_edge[] = {0, 0, 1, 1, 0, 1};
    int output_edge[6];
    edge(input_edge, output_edge, 6);
    printf("Original: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d", input_edge[i]);
    }
    printf("\nOutput: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d", output_edge[i]);
    }
    printf("\n");

    // Setup for shift
    char message[50] = "Go ahead, make my day.";
    shift(message, 3);
    printf("%s\n", message);
    shift(message, 23);
    printf("%s\n", message);

    // Setup for is_all_uppercase
    char bad_string[] = "Hello";
    int result = is_all_uppercase(bad_string);
    printf("%d\n", result);

    char good_string[] = "HELLO";
    result = is_all_uppercase(good_string);
    printf("%d\n", result);
    // One word from user input
    char oneWord[50];
    scanf("%s", oneWord);
    printf("%d\n", is_all_uppercase(oneWord));

    // Test split_time

    int secondsSinceMidnight = 60*60 + 60 + 10;
    int min, hr, sec;
    split_time(secondsSinceMidnight, &hr, &min, &sec);
    printf("%d hours, %d minutes, %d seconds, since midnight\n", hr, min, sec);

    return 0;
}

void edge(int *a1, int *a2, int n)
{
    // Requirements:
    // First output element will be a zero as there is no previous to compare with
    // Must use pointer arithmetic, assume a1 and a2 are of length n
    // 0 if bit and previous are the same
    // 1 if bit and previous are different
    // a1 contains data, a2 is our output
    int *p = a1 + 1, *q = a2;
    *q = 0;
    q++;
    // Both p and q enter this loop at element 1
    for (; p < a1 + n; p++, q++)
    {
        if (*p == *(p - 1))
            *q = 0;
        else
            *q = 1;
    }
}

void shift(char *message, int shift)
{
    char *p;
    for (p = message; *p != '\0'; ++p)
    {
        if (*p >= 'A' && *p <= 'Z')
            *p = 'A' + ((*p + shift - 'A') % 26);
        else if (*p >= 'a' && *p <= 'z')
            *p = 'a' + ((*p + shift - 'a') % 26);
    }
}

int is_all_uppercase(char str[])
{
    int flag = 1; // Assume true until proven false approach
    char *p = str;
    for (; *p != '\0'; ++p)
        if (*p >= 'a' && *p <= 'z')
            return 0;
    return flag;
}

void split_time(int total_sec, int *hr, int *min, int *sec)
{                                // Given seconds since midnight. Split times
    int minute = total_sec / 60; // At this point contains hours as well
    *sec = total_sec % 60; // Remainder from this is the seconds

    int hours = minute / 60;
    minute = minute % 60; // Remainder from this is the minutes.

    *min = minute;
    *hr = hours;
}
