// Problem#: 1152
// Submission#: 2798956
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int r[60] = {1, 14, 25, 21, 29, 18, 5, 16, 27, 19, 8, 4, 12, 23, 10, 6, 17, 30, 22, 26, 13, 2, 15, 28, 24, 11, 3, 7, 20, 9}, n, j=30,i;
    while (j < 60)
        r[j++] = r[j-30];
    while (scanf("%d", &n) && n+1) {
        for (i = 0; i < 30; i++) {
            if (n == r[i]) {
                printf("%d", r[i]);
                i++;
                while (r[i]-n) {
                    printf(" %d", r[i]);
                    i++;
                }
                printf("\n");
            }
        }
    }
    return 0;
}                                 