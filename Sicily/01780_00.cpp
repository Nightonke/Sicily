// Problem#: 1780
// Submission#: 2515835
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int t, length, i, j, sum;
    char a[11];
    scanf("%d\n", &t);
    while (t--) {
        gets(a);
        sum = 0;
        for (i = 0; i < 11; i++) {
            if (!(a[i] >= '0' && a[i] <= '9'))
                a[i] = '\0';
        }
        length = strlen(a);
        for (i = 0; i < length; i++) {
            printf("%c", a[i]);
            if (a[i] > '2' && a[i] < '5')
                a[i] -= 1;
            if (a[i] > '5' && a[i] < '8')
                a[i] -= 2;
            if (a[i] > '8')
                a[i] -= 3;
        }
        j = 0;
        for (i = length - 1; i >= 0; i--) {
            sum = sum + (a[i] - '0')* (int)pow(7, j);
            j++;
        }
        printf(": %d\n", sum);
    }
    return 0;
}                                 