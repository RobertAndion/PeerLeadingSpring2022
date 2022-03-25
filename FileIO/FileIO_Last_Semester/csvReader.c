#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500

int main() {
    char homeTeam[MAX_SIZE], opposingTeam[MAX_SIZE], homeScore[MAX_SIZE], opposingScore[MAX_SIZE];
    FILE *fp = fopen("./games.csv", "r");
    if (fp == NULL) {
        printf("Failed to find the file.\n");
        return -1;
    }

    while(!feof(fp) && !ferror(fp)) { // While runs when the condition is true
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", homeTeam, opposingTeam, homeScore, opposingScore);
        printf("%9s %9s %9s %9s\n",homeTeam, opposingTeam, homeScore, opposingScore);
    }
}