// Problem#: 1018
// Submission#: 2796109
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#define A 5 * 4 * 3 * 2 * 1
using namespace std;
int d[5][2],t[5][2],p[A][5];
int n(int a, int b) {
    if (t[a][0] != t[b][0]) {
        return t[a][0] < t[b][0] ? a : b;
    } else {
        return t[a][1] < t[b][1] ? a : b;
    }
}
void m() {
    int e[5];
    int j = 1;
    for (int i = 0; i < 5; i++) {
        p[0][i] = i;
        e[i] = i;
    }
    while (next_permutation(e, e + 5)) {
        for (int i = 0; i < 5; i++) {
            p[j][i] = e[i];
        }
        j++;
    }
}
void i() {
    char e[5];
    for (int i = 0; i < 5; i++) {
        scanf("%s", &e);
        if (e[0] == '1' && e[1] == '0') {
            d[i][0] = 9;
            d[i][1] = e[2];
        } else if (e[0] == 'A') {
            d[i][0] = 0;
            d[i][1] = e[1];
        } else if (e[0] == 'J') {
            d[i][0] = 10;
            d[i][1] = e[1];
        } else if (e[0] == 'Q') {
            d[i][0] = 11;
            d[i][1] = e[1];
        } else if (e[0] == 'K') {
            d[i][0] = 12;
            d[i][1] = e[1];
        } else {
            d[i][0] = e[0] - '1';
            d[i][1] = e[1];
        }
    }
}
bool check() {
    if (t[1][1] != t[0][1])
        return false;
    int m = t[1][0];
    int l = n(n(2, 3), 4);
    t[1][0] = (t[1][0] + l - 1) % 13;
    int f = -1, r = -1;
    for (int i = 2; i < 5; i++) {
        if (i != l && f == -1) {
            f = i;
            continue;
        }
        if (i != l && r == -1) {
            r = i;
        }
    }
    if (n(f, r) != f) {
        t[1][0] = (t[1][0] + 3) % 13;
    }
    if (t[0][0] == t[1][0] && t[0][1] == t[1][1]) {
        t[1][0] = m;
        return true;
    }
    else
        return false;
}
void o(int k) {
    printf("Problem %d:", k);
    for (int i = 0; i < 5; i++) {
        if (t[i][0] == 0) {
            printf(" A");
        } else if (t[i][0] == 10) {
            printf(" J");
        } else if (t[i][0] == 11) {
            printf(" Q");
        } else if (t[i][0] == 12) {
            printf(" K");
        } else {
            printf(" %d", t[i][0] + 1);
        }
        printf("%c", t[i][1]);
    }
    printf("\n");
}
int main() {
    int c;
    m();
    scanf("%d", &c);
    for (int k = 1; k <= c; k++) {
        bool is_ok = false;
        i();
        for (int i = 0; i < A && !is_ok; i++) {
            for (int j = 0; j < 5; j++) {
                t[j][0] = d[p[i][j]][0];
                t[j][1] = d[p[i][j]][1];
            }
            is_ok = check();
        }
        o(k);
    }
    return 0;
}                                 