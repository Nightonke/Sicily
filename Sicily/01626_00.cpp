// Problem#: 1626
// Submission#: 2698324
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int r[1010];

void ready() {
    int i, j;
    for (i = 0; i < 1010; i++) {
        r[i] = 1;
    }
    for (i = 0; i < 1010; i++) {
        for (j = 1; j * 2 <= i; j++) {
            r[i] += r[j];
        }
    }
}

int main() {
    ready();
    int n, t, counter = 0;
    scanf("%d", &n);
    while (n--) {
        counter++;
        scanf("%d", &t);
        printf("%d %d\n", counter, r[t]);
    }
    return 0;
}                                 