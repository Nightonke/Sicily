// Problem#: 1689
// Submission#: 2496642
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, k, n, i, time, j, jj, jilu;
    char number[101], acorwa[101][7], accept[101], wrong[101], min;
    scanf("%d", &t);
    while (t--) {
        k = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d %c %s", &time, &number[i], acorwa[i]);
        }
        for (i = 0; i < n; i++) {
            if (acorwa[i][0] == 'A' && number[i] != '\0') {
                accept[k] = number[i];
                for (j = 0; j < n; j++) {
                    if (number[j] == accept[k])
                        number[j] = '\0';
                }
                k++;
            }
        }
        j = 0;
        for (i = 0; i < n; i++) {
            if (number[i] != '\0') {
                wrong[j] = number[i];
                for (jj = 0; jj < n; jj++) {
                    if (number[jj] == wrong[j])
                        number[jj] = '\0';
                }
                j++;
            }
        }
        printf("Accept: ");
        for (i = 0; i < k; i++) {
            min = 'Z';
            for (jj = 0; jj < k; jj++) {
                if (accept[jj] <= min && accept[jj] != '\0') {
                    min = accept[jj];
                    jilu = jj;
                }
            }
            if (k)
                printf("%c", accept[jilu]);
            accept[jilu] = '\0';
        }
        printf("\nWrong: ");
        for (i = 0; i < j; i++) {
            min = 'Z';
            for (jj = 0; jj < j; jj++) {
                if (wrong[jj] <= min && wrong[jj] != '\0') {
                    min = wrong[jj];
                    jilu = jj;
                }
            }
            if (j)
                printf("%c", wrong[jilu]);
            wrong[jilu] = '\0';
        }
        printf("\n\n");
    }
    return 0;
}                                 