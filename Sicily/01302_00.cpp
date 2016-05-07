// Problem#: 1302
// Submission#: 2777131
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    long long w;
    while (scanf("%lld", &w) && w)
        printf("%lld\n", w == 1 ? 1 : 2 + (w + 2) * (w - 3) / 2);
    return 0;
}                                 