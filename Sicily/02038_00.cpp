// Problem#: 2038
// Submission#: 2447684
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int t, i, j, k, longb, longc, longa, i1;
    char a[110], b[110], c[110], b1[110], c1[110];
    scanf("%d", &t);
    while (t--) {
        j = 0;
        scanf("%s", a);
        longa = strlen(a);
        for (i = 0; a[i] != '_' && (i - 1) != longa; i++)
            b[i] = a[i];
        if (longa != i - 1) {
            longb = i;
        for (i1 = i + 1; a[i1] != '\0'; i1++) {
            c[j] = a[i1];
            j++;
        }
        longc = j;
        for (k = 0; longb >= 0; longb--) {
            b1[k] = b[longb - 1];
            k++;
        }
        b1[k] = '\0';
        for (k = 0; longc >= 0; longc--) {
            c1[k] = c[longc - 1];
            k++;
        }
        c1[k] = '\0';
        printf("%s_%s\n", b1, c1);
        }
        if (longa == i - 1) {
            longb = longa;
            for (k = 0; longb >= 0; longb--) {
            b1[k] = b[longb - 1];
            k++;
            }
            printf("%s\n", b1);
        }
    }
    return 0;
}                                 