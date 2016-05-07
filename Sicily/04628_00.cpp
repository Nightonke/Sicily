// Problem#: 4628
// Submission#: 2375040
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, i, j, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        for(i = 1; i <= a; i++)
            printf("*");
        printf("\n");
        for (i = 1; i <= b - 2; i++) {
            printf("*");
            for (j = 1; j <= a - 2; j++) {
                printf(" ");
            }
            printf("*\n");
        }
        for (i = 1; i <= a; i++)
            printf("*");
            printf("\n\n");
    }
    return 0;
}                                 