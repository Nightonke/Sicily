// Problem#: 4315
// Submission#: 2373482
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, a[2000], i, j, k, linshi, counter0, counter1, counter2, counter3, counter4, counter5, counter6, counter7, counter8, counter9;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        counter0 = counter1 = counter2 = counter3 = counter4 = counter5 = counter6 = counter7 = counter8 = counter9 = 0;
        j = 0;
        for (i = 1; i <= n; i++) {
            a[j] = i;
            j++;
        }
        for (k = 0; k < j; k++) {
            while (a[k] != 0) {
                linshi = a[k] % 10;
                a[k] = a[k] / 10;
                if (linshi == 0)
                    counter0++;
                if (linshi == 1)
                    counter1++;
                if (linshi == 2)
                    counter2++;
                if (linshi == 3)
                    counter3++;
                if (linshi == 4)
                    counter4++;
                if (linshi == 5)
                    counter5++;
                if (linshi == 6)
                    counter6++;
                if (linshi == 7)
                    counter7++;
                if (linshi == 8)
                    counter8++;
                if (linshi == 9)
                    counter9++;
            }
        }
        printf("%d %d %d %d %d %d %d %d %d %d\n", counter0, counter1, counter2, counter3, counter4, counter5, counter6, counter7, counter8, counter9);
    }
    return 0;
}                                 