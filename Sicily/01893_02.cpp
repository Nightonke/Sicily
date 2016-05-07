// Problem#: 1893
// Submission#: 2760044
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

long long c[31];
int n, i;

void initialize() {
    c[0] = c[1] = 1;
    for (i = 2; i <= 30; i++) {
        c[i] = (4 * i - 2) * c[i - 1] / (i + 1);
    }
}

int main() {
    initialize();
    while (scanf("%d", &n) && n) {
        printf("%lld\n", c[n]);
    }
    return 0;
}                                 