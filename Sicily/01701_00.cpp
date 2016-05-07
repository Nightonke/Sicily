// Problem#: 1701
// Submission#: 2501012
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a[1001], t, n, i, sum, counter = 1;
    a[0] = 1;
    scanf("%d", &t);
    for (i = 1; i <= 1000; i++) {
        a[i] = a[i - 1] + i + 1;
    }
    while (t--) {
        scanf("%d", &n);
        sum = 0;
        for (i = 0; i < n; i++)
            sum = sum + a[i];
        printf("%d: %d %d\n", counter, n, sum);
        counter++;
    }
    return 0;
}                                 