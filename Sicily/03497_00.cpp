// Problem#: 3497
// Submission#: 2377231
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int i, i1, c, b, a;
    for(i = 100; i <= 999; i++) {
        i1 = i;
        c = i1 % 10;
        i1 = i1 / 10;
        b = i1 % 10;
        i1 = i1 / 10;
        a = i1 % 10;
        if (i == a * a * a + b * b * b + c * c * c)
            printf("%d\n", i);
    }
    return 0;
}                                 