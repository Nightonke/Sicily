// Problem#: 1394
// Submission#: 2455265
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int main() {
    int b, n, kaifang1, kaifang2;
    double kaifang;
    while (1) {
        scanf("%d %d", &b, &n);
        if (b == 0 && n == 0)
            break;
        kaifang = pow (b, 1.0 / n);
        kaifang1 = (int)kaifang;
        kaifang2 = kaifang1 + 1;
        if ((pow (kaifang1, n) - b) * (pow (kaifang1, n) - b) >= (pow (kaifang2, n) - b) * (pow (kaifang2, n) - b))
            printf("%d\n", kaifang2);
        else
            printf("%d\n", kaifang1);
    }
    return 0;
}                                 