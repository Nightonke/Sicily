// Problem#: 1020
// Submission#: 2452483
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int getmod(int chushu, char big[]) {
    int j = 0, k = 0;
    for (j = 0; big[j] != '\0'; j++) {
        k = (k * 10 + big[j] - '0') % chushu;
    }
    return k;
}
int main() {
    int t, n, i, a[110], k;
    char b[500];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%s", b);
        printf("(");
        for (i = 0; i < n; i++) {
            k = getmod(a[i], b);
            printf("%d", k);
            if (i != n - 1)
                printf(",");
        }
        printf(")\n");
    }
    return 0;
}                                 