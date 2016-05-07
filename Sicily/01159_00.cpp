// Problem#: 1159
// Submission#: 2582955
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int a1[110], b1[110];
char a[110];

void add() {
    int i, length = strlen(a);
    for (i = 0; i < length; i++)
        a1[i] = a[length - i - 1] - '0';
    for (i = 0; i < 110; i++) {
        if (b1[i] + a1[i] >= 10)
            b1[i + 1] ++;
        b1[i] = (b1[i] + a1[i]) % 10;
    }
}


int main() {
    int n, i, k;
    while (scanf("%d", &n) == 1) {
        memset(b1, 0, sizeof(b1));
        for (i = 0; i < n; i++) {
            memset(a, '\0', sizeof(a));
            memset(a1, 0, sizeof(a1));
            scanf("%s", a);
            add();
        }
        k = 109;
        while (b1[k] == 0 && k > 0)
            k--;
        for (i = k; i >= 0; i--)
            printf("%d", b1[i]);
        printf("\n");
    }
    return 0;
}                                 