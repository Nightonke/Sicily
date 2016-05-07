// Problem#: 1793
// Submission#: 2612759
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int judge(int a, int b) {
    int min, max, i;
    min = a > b ? b : a;
    max = a + b - min;
    for (i = 2; i <= min; i++) {
        if (max % i == 0 && min % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    long long int g, l, a, i, ans, min;
    while (scanf("%lld %lld", &g, &l), g || l) {
        min = 999999999;
        a = l / g;
        for (i = 1; i * i <= a; i++) {
            if (a % i == 0 && judge(i, a / i)) {
                if ((long long int)fabs(i - a / i) < min) {
                    min = (long long int)fabs(i - a / i);
                    ans = i;
                }
            }
            if (g * min == g)
                break;
        }
        printf("%lld %lld %lld\n", g * min, g * (ans > a / ans ? a / ans : ans), g * (ans < a / ans ? a / ans : ans));
    }
    return 0;
}                                 