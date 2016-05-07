// Problem#: 1294
// Submission#: 2437955
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a, b, c, a1 = 1, i;
    scanf("%d %d %d", &a, &b, &c);
    for (i = 0; i < b; i++) {
        a1 = a * a1 % c;
    }
    printf("%d\n", (a1 + c) % c);
    return 0;
}                                 