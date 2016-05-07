// Problem#: 6774
// Submission#: 2652123
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int i, n;
    double min, k, u, b[101] = {0};
    scanf("%lf%lf%d", &k, &u, &n);
    min = k / u;
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &k, &u);
        b[i] = k / u;
        if (b[i] < min) {
            min = b[i];
        }
    }
    printf("%.2lf\n", min * 1000);
    return 0;
}                                 