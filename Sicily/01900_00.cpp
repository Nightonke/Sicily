// Problem#: 1900
// Submission#: 3590598
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int last(char s[]) {
    return s[strlen(s) - 1] - 'a';
}

void mul(int a[52][52], int x[52][52]) {
    int t[52][52];
    int i, j, k;
    memset(t, 0, sizeof(t));
    for (i = 0; i < 52; i++)
        for (j = 0; j < 52; j++)
            for (k = 0; k < 52; k++)
                t[i][j] = (t[i][j] + a[i][k] * x[k][j]) % 10001;
    memcpy(a, t, sizeof(t));
}

int main() {
    int m, n, b[52][52], x[52][52], i, j, cs;
    char s[11];
    scanf("%d", &cs);
    while (cs--) {
        memset(b, 0, sizeof(b));
        memset(x, 0, sizeof(x));
        scanf("%d", &m);
        while (m--) {
            scanf("%s", s);
            x[s[0] - 'a'][last(s)]++;
        }
        scanf("%s", s);
        int vs = last(s);
        scanf("%s", s);
        int vt = s[0] - 'a';
        scanf("%d", &n);
        mul(x, x);
        for (i = 0; i < 26; i++) {
            x[i + 26][i] = 1;
            x[i + 26][i + 26] = 1;
            b[i][i] = 1;
            b[i][i + 26] = 1;
        }
        int p = (n - 1) / 2;
        for (i = 0; (1 << i) <= p; i++) {
            if (p & (1 << i)) mul(b, x);
            mul(x, x);
        }
        printf("%d\n", b[vs][vt]);
    }
    return 0;
}                                 