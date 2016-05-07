// Problem#: 1167
// Submission#: 2486460
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int t, k, bingonum, i, missnum, missall, j;
    char a[60], b[60];
    scanf("%d\n", &t);
    for (k = 1; k <= t; k++) {
        gets(a);
        gets(b);
        bingonum = missall = 0;
        for (i = 0; i < strlen(a); i++) {
            missnum = 0;
            for (j = 0; j < strlen(b); j++) {
                if (a[i] == b[j]) {
                    bingonum++;
                    b[j] = '!';
                    break;
                }
                if (a[i] != b[j]) {
                    missnum++;
                }
            }
            if (missnum == strlen(b))
                missall++;
        }
        printf("Case #%d:  %d\n", k, strlen(b) - bingonum + missall);
    }
    return 0;
}                                 