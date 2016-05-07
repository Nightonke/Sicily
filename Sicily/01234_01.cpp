// Problem#: 1234
// Submission#: 2772542
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<algorithm>
int main() {
    int n, i;
    double sum, a[20];
    while (scanf("%d", &n) && n) {
        for (sum = i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
            sum += a[i];
        }
        std :: sort(a, a + n);
        for (i--; i >= 0; i--) {
            sum -= a[i];
            if (sum >= a[i])
                break;
        }
        if (i>=0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}                                 