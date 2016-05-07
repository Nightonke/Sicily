// Problem#: 14181
// Submission#: 3705500
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
    int c;
    char C[30];
    scanf("%d\n", &c);
    while (c--) {
        int n, m;
        scanf("%d%d\n", &n, &m);
        printf("%d\n", n - 1);
        while (m--) gets(C);
    }
    return 0;
}                                 