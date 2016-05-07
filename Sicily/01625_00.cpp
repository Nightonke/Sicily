// Problem#: 1625
// Submission#: 2446879
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, counter = 0, b[3], a[4][7], i, j;
    scanf("%d", &t);
    while (t--) {
        counter++;
        scanf("%d:%d:%d", &b[0], &b[1], &b[2]);
        for (i = 0; i < 3; i++) {
            for (j = 5; j >= 0; j--) {
                a[i][j] = b[i] % 2;
                b[i] = b[i] / 2;
            }
        }
        printf("%d ", counter);
        for (i = 0; i < 6; i++)
            for (j = 0; j < 3; j++)
                printf("%d", a[j][i]);
        printf(" ");
        for (i = 0; i < 3; i++)
            for (j = 0; j < 6; j++)
                printf("%d", a[i][j]);
        printf("\n");
    }
    return 0;
}                                 