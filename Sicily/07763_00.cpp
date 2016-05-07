// Problem#: 7763
// Submission#: 2704786
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
    if (son != 0) { 
        temp = gcd(son, mother);
        son /= temp;
        mother /= temp;
    } else {
        mother = 1;
    }
    printf("%d / %d\n", son, mother);
}

int main() {
    int n, m, i, j, a[10005], sum, temp, k;
    while (scanf("%d%d", &n, &m), n && m) {
        for (k = 0, i = 1, j = 1, sum = 0; i <= n * m; i++, j++) {
            scanf("%d", &temp);
            if (j == m) {
                a[k++] = temp;
                j = 0;
                sum += temp;
            }
        }
        for (i = 0; i < k; i++) {
            ans(a[i], sum);
        }
    }
    return 0;
}                                 