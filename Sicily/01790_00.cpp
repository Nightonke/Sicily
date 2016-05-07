// Problem#: 1790
// Submission#: 2699325
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int get_remainder(char a[], int divisor) {
    int length, i, d, b[1010], c[1010];
    length = (int)strlen(a);
    for (i = 0; i < length; i++) {
        b[i] = a[length - i - 1] - '0';
    }
    d = 0;
    for (i = length - 1; i >= 0; i--) {
        d = d * 10 + b[i];
        c[i] = d / divisor;
        d = d % divisor;
    }
    return d;
}

int main() {
    int t;
    char a1[1010], a2[1010];
    scanf("%d", &t);
    while (t--) {
        memset(a1, '\0', sizeof(a1));
        memset(a2, '\0', sizeof(a2));
        scanf("%s %s", a1, a2);
        if (strcmp(a1, a2) != 0) {
            printf("NO\n");
            continue;
        } else {
            if (get_remainder(a1, 11) == 0) {
                printf("YES\n");
                continue;
            } else {
                printf("NO\n");
                continue;
            }
        }
    }
    return 0;
}                                 