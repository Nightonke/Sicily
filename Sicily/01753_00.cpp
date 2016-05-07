// Problem#: 1753
// Submission#: 2494520
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
char b[1000000];
int main() {
    int k, length, i, j, sum, c[10], u, m;
    char a[40000], sign, c1[40000];
    while (gets(a), a[0] != 'X' && a[1] != 'X' && a[2] != 'X') {
        k = 0;
        length = strlen(a);
        a[length] = '\0';
        j = 0;
        for (m = 0; m < length; m++) {
            if (a[m] >= '0' && a[m] <= '9') {
                c1[m] = a[m];
            }
            if (a[m] < '0' || a[m] > '9') {
                break;
            }
        }
        for (i = m; i < length + 1; i++) {
            sum = 0;
            if (a[i] < '0' || a[i] > '9') {
                for (u = j - 1; u >= 0; u--) {
                    sum = sum + c[u] * (int)pow(10, j - u - 1);
                }
                j = 0;
                for (u = 0; u < sum - 1; u++) {
                    b[k] = sign;
                    k++;
                }
                b[k] = a[i];
                k++;
            }
            else {
                if (a[i - 1] < '0' || a[i - 1] > '9')
                    sign = a[i - 1];
                c[j] = a[i] - '0';
                j++;
            }
        }
        for (i = 0; i < m; i++)
            printf("%c", c1[i]);
        printf("%s\n", b);
        memset(b, '\0', sizeof(b));
    }
    return 0;
}                                 