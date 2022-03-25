#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 500
int main()
{
    FILE *fp = fopen("games.txt", "r");
    char line[MAX_SIZE];
    int row, col;
    if (fscanf(fp, "%d\t%d", &row, &col) != 2)
    {
        return -1;
    }
    printf("%d %d\n", row, col);
    fgets(line, MAX_SIZE, fp);

    char homeTeam[MAX_SIZE], opposingTeam[MAX_SIZE], homeScore[MAX_SIZE], opposingScore[MAX_SIZE];
    char storage[row][col][MAX_SIZE];
    int i = 0;
    int largestWin = -1;
    while (fscanf(fp, "%s\t%s\t%s\t%s", homeTeam, opposingTeam, homeScore, opposingScore) == 4)
    {
        if (i < 2)
        {
            ++i;
            continue;
        }
        int ourScore, theirScore;
        ourScore = atoi(homeScore);
        theirScore = atoi(opposingScore);
        if ((ourScore - theirScore) > largestWin)
            largestWin = ourScore - theirScore;
        /*
        Case 1: Storage, All the same type, we will try this case.
        1. [1,2,3,4]
        2. [1,2,3,4]
        3. [1,2,3,4]
        4. [1,2,3,4]
        Case 2: Usage, Store as its own type.
        */
        printf("%10s%10s%10s%10s\n", homeTeam, opposingTeam, homeScore, opposingScore);
    }
    printf("%d\n",largestWin);
    /*while (fgets(line,MAX_SIZE,fp) != NULL) {
        printf("%s\n",line);
    }*/
}