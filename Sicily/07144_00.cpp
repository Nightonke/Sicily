// Problem#: 7144
// Submission#: 2447919
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a[110], t, counter, i, n, j, k;
    scanf("%d", &t);
    while (t--) {
        counter = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n - 2; i++)
            for (j = i + 1; j < n - 1; j++)
                for (k = j + 1; k < n; k++) {
                    if (a[i] + a[j] > a[k] && a[i] - a[j] < a[k])
                        if (a[i] + a[k] > a[j] && a[i] - a[k] < a[j])
                            if (a[j] + a[k] > a[i] && a[j] - a[k] < a[i])
                                counter++;
                }
        printf("%d\n", counter);
    }
    return 0;
}                                 