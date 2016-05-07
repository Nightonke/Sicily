// Problem#: 2388
// Submission#: 2470372
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a, b, c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0)
            break;
        if (c * a == b * b)
            printf("GP %d\n", c * b / a);
        else if (c - b == b - a)
            printf("AP %d\n", b - a + c);
    }
    return 0;
}                                 