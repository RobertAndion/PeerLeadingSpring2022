#include <stdio.h>

int main() {
    // For Loops
    int i;
    int j = 5;

    for(i = 0; i < 10; ++i) { // (Initialization; Condition; Incrementation)
        printf("%d\n",(i + 1));
    }
    printf("\n#########\n");
    // While loops  &  Break and Continue
    i = 0;
    while (i < 10001) {
        if (i > 100)
            break;
        if (i % 2 == 1) {
            i++;
            continue;
        }
        
        printf("%d\n",i); 
        i++;
    }
    i = 15;
    int x = i;
    for(; i < x + 10; i++);
    printf("%d\n",i);
    // Read/Write characters
    char c, d;
    scanf("%c%c",&c, &d);
    printf("%c %c\n",c, d);

    return 0;
}