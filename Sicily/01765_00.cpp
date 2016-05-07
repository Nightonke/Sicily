// Problem#: 1765
// Submission#: 2493440
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int isprime(int n) {
    int i;
    if (n == 0 || n == 1)
        return 0;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    int standardnum[27] = {0}, i, j, length, max, min;
    char standard[] = "abcdefghijklmnopqrstuvwxyz", a[101];
    while (scanf("%s", a) == 1) {
        length = strlen(a);
        for (i = 0; i < length; i++) {
            for (j = 0; j < 27; j++) {
                if (a[i] == standard[j])
                    standardnum[j]++;
            }
        }
        max = standardnum[0];
        min = 101;
        for (i = 0; i < 27; i++) {
            if (standardnum[i] > max)
                max = standardnum[i];
            if (standardnum[i] <= min && standardnum[i] != 0)
                min = standardnum[i];
        }
        if (isprime(max - min))
            printf("Lucky Word\n%d\n", max - min);
        else
            printf("No Answer\n0\n");
        memset(standardnum, 0, sizeof(standardnum));
    }
    return 0;
}                                 