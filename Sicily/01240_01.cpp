// Problem#: 1240
// Submission#: 2487334
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    long long int i, nine;
    char a[20], b[20];
    while (gets(a), a[0] != '0') {
        nine = 0;
        strcpy(b, a);
        for (i = 0; i < strlen(b); i++) {
            a[i] = a[i] - '0';
            if (a[i] > 4)
                a[i]--;
        }
        for (i = strlen(b) - 1; i >= 0; i--) {
            nine = nine + a[i] * pow(9, strlen(b) - i - 1);
        }
        printf("%s: %lld\n", b, nine);
        memset(a, '\0', 20);
        memset(b, '\0', 20);
    }
    return 0;
}                                 