#include <stdio.h>

int main() {
    char line[500];
    FILE * fp = fopen("games.txt","r");
    fgets(line,500,fp);
    while (fgets(line,500,fp) != NULL) {
        printf("%s\n",line);
    }

}