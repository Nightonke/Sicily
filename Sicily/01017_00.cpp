// Problem#: 1017
// Submission#: 2488264
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    double a[13][3], interest, sum, error, half;
    int counter, n, i, k;
    counter = 1;
    while (scanf("%d", &n), n != -1) {
        for (i = 0; i <= n; i++) {
            scanf("%lf %lf", &a[i][0], &a[i][1]);
        }
        interest = 0.5;
        k = 2;
        error = 1;
        while (fabs(error) > 0.000001) {
            sum = 0;
            for (i = 0; i < n; i++) {
                sum = sum + a[i][1] * pow(1 + interest, a[n][0] - a[i][0] + 1);
            }
            error = sum - a[n][1];
            half = pow(0.5, k);
            k++;
            if (error < 0)
                interest = interest + half;
            if (error > 0)
                interest = interest - half;
        }
        if (counter != 1)
            printf("\n");
        printf("Case %d: %.5lf\n", counter++, interest);
    }
    return 0;
}                                 