// Problem#: 1259
// Submission#: 2585010
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int prime[1500], number[10001];

void makeprime() {
    memset(number, 0, sizeof(number));
    int i = 0, k, j;
    for (k = 2; k < 10001; k++) {
        if (number[k] == 0) {
            prime[i++] = k;
            for (j = 2; j * k < 10001; j++)
                number[j * k] = 1;
        }
    }
}

int main() {
    int n, i, j, sum, counter;
    makeprime();
    while (scanf("%d", &n), n) {
        counter = 0;
        for (i = 0; prime[i] <= n; i++) {
            sum = 0;
            for (j = i; sum <= n; j++) {
                sum += prime[j];
                if (sum == n)
                    counter++;
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 