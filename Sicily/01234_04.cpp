// Problem#: 1234
// Submission#: 2772525
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    bool is_ok;
    int n, i, j;
    double sum, max, a[21];
    while (scanf("%d", &n) && n) {
        for (i = 0, max = 0, sum = 0, is_ok = false; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        sort(a, a + n);
        for (i = n - 1; i >= 0; i--) {
            max = a[i];
            for (j = 0, sum = 0; j < i; j++) {
                sum += a[j];
            }
            if (sum >= max) {
                is_ok = true;
                break;
            }
        }
        if (is_ok) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}                                 