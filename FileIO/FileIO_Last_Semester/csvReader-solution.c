#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500
int main() {
    FILE *fp = fopen("games.csv", "r");
    char line[MAX_SIZE];
    char tampaTeam[MAX_SIZE], opposingTeam[MAX_SIZE], tampaScore[MAX_SIZE], opposingScore[MAX_SIZE];
    while(!feof(fp) && !ferror(fp)) {
        if (fscanf(fp, "%[^,],%[^,],%[^,],%[^,\n]\n", tampaTeam, opposingTeam, tampaScore, opposingScore) != 4)
            break;
        printf("%9s %9s %9s %9s\n",tampaTeam, opposingTeam, tampaScore, opposingScore);
    }
}