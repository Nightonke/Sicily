// Problem#: 7763
// Submission#: 2704779
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int gcd(int son, int mother) {
    if (mother == 0)
        return son;
    else
        return gcd(mother, son % mother);
}

void ans(int son, int mother) {
    int temp;
    temp = gcd(son, mother);
    son /= temp;
    mother /= temp;
    printf("%d / %d\n", son, mother);
}

int main() {
    int n, m, i, j, a[10005][35], sum;
    while (scanf("%d%d", &n, &m), n && m) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (i = sum = 0; i < n; i++) {
            sum += a[i][m - 1];
        }
        for (i = 0; i < n; i++) {
            ans(a[i][m - 1], sum);
        }
    }
    return 0;
}                                 