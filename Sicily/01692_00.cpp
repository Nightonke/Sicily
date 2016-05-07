// Problem#: 1692
// Submission#: 2475073
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, m;
    while (scanf("%d %d", &m, &n), n||m) {
        if (n * m % 8 == 0 && n != 1 && m != 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}                                 