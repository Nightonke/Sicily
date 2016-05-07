// Problem#: 4312
// Submission#: 2372748
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, a, b, linshia, linshib;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        linshia = linshib = 0;
        while (a != 0) {
            linshia = linshia * 10 + a % 10;
            a = a / 10;}
        while (b != 0) {
            linshib = linshib * 10 + b % 10;
            b = b / 10;}
        printf("%d\n", linshia + linshib);
    }
    return 0;
}                                 