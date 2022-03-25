#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500
int main () {
    // Convert normal teams.txt into a csv.
    // fprintf()
    char homeTeam[MAX_SIZE], opposingTeam[MAX_SIZE], homeScore[MAX_SIZE], opposingScore[MAX_SIZE];
    FILE *fwo = fopen("./result.csv","w");
    FILE *fp = fopen("./games_to_convert.txt", "r");
    if (fp == NULL) {
        printf("Failed to find the file.\n");
        return -1;
    }
    while(!feof(fp) && !ferror(fp)) { // While runs when the condition is true
        fscanf(fp, "%[^ ] %[^ ] %[^ ] %[^\n]\n", homeTeam, opposingTeam, homeScore, opposingScore);
        fprintf(fwo, "%s,%s,%s,%s\n",homeTeam, opposingTeam, homeScore, opposingScore);
    }
}