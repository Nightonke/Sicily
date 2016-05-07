// Problem#: 13858
// Submission#: 3650504
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int n, x, y, z, a[20005], b[20005], ans = 0;
    scanf("%d%d%d%d", &n, &x, &y, &z);
    for (int i = 0; i < n; i++) scanf("%d%d", a + i, b + i);
    sort(a, a + n);
    sort(b, b + n);
    for (int i = n - 1, j = n - 1; i >= 0; i--) {
        while (j >= 0 && b[j] >= a[i]) j--;
        ans = max(ans, (n - i - 1) * x + (j + 1) * z + (i - j) * y);
    }
    printf("%d\n", ans);
    return 0;
}                                 