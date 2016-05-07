// Problem#: 1293
// Submission#: 2437927
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a, b, i, k, counter = 0, max = 0;
    scanf("%d %d", &a, &b);
    for (i = a; i <= b; i++) {
        k = i;
        while (k != 1) {
            if (k % 2 == 0)
                k = k / 2;
            else
                k = 3 * k + 1;
            counter++;
        }
        if (counter > max)
            max = counter;
        counter = 0;
    }
    printf("%d\n", max + 1);
    return 0;
}                                 