// Problem#: 1704
// Submission#: 2700348
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

void print(int i, int j, int k) {
    printf("%d at four cents each\n", i);
    printf("%d at two for a penny\n", j);
    printf("%d at four for a penny\n\n", k);
}

int main() {
    int counter = 0, n, i, j, has_solution, k1, k2;
    while (scanf("%d", &n), n) {
        counter++;
        printf("Case %d:\n", counter);
        printf("%d pencils for %d cents\n", n, n);
        has_solution = 0;
        for (i = 1; i * 4 <= n && i <= n; i++) {
            for (j = 1; j <= 2 * (n - i * 4) && i + j <= n; j++) {
                k1 = 4 * n - 4 * 4 * i - 2 * j;
                k2 = n - i - j;
                if (k1 == k2 && k1 != 0) {
                    print(i, j, k1);
                    has_solution = 1;
                }
            }
        }
        if (!has_solution)
            printf("No solution found.\n\n");
    }
    return 0;
}                                 