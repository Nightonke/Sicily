// Problem#: 1732
// Submission#: 3583806
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

struct number {
    short n[1050], l;
    number() {
        for (int i = 0; i < 1050; i++) n[i] = 0;
        l = 0;
    }
    number(char * a) {
        int length = strlen(a);
        l = length;
        for (int i = length - 1; i >= 0; i--) n[length - 1 - i] = a[i] - '0';
        for (int i = length; i < 1050; i++) n[i] = 0;
    }
};

int cmp(number & a, number & b) {
    if (a.l > b.l) return 1;
    if (a.l < b.l) return -1;
    for (int i = a.l - 1; i >= 0; i--) {
        if (a.n[i] > b.n[i]) return 1;
        else if (a.n[i] < b.n[i]) return -1;
    }
    return 0;
}

void divide2(number & a) {
    if (a.l == 1) {
        a.n[0] = 0;
        a.l = 0;
        return;
    }
    for (int i = 0; i < a.l; i++) a.n[i] = a.n[i + 1];
    a.n[--a.l] = 0;
}

number subtraction(number a, number & b) {
    number ans;
    for (int i = 0; i < a.l; i++) {
        if (a.n[i] >= b.n[i]) {
            ans.n[i] = a.n[i] - b.n[i];
        } else {
            ans.n[i] = a.n[i] + 2 - b.n[i];
            a.n[i + 1] -= 1;
        }
    }
    ans.l = 1049;
    while (ans.l && ans.n[ans.l - 1] == 0) ans.l--;
    return ans;
}

void gcd(number a, number b) {
    int plus2 = 0;
    while (a.l && b.l) {
        if (a.n[0]) {
            if (b.n[0]) {
                if (cmp(a, b) == -1) b = subtraction(b, a);
                else a = subtraction(a, b);
            } else {
                divide2(b);
            }
        } else {
            if (b.n[0]) {
                divide2(a);
            } else {
                divide2(a);
                divide2(b);
                plus2++;
            }
        }
    }
    if (b.l) for (int i = b.l - 1; i >= 0; i--) printf("%d", b.n[i]);
    else for (int i = a.l - 1; i >= 0; i--) printf("%d", a.n[i]);
    while (plus2--) printf("0");
    printf("\n");
}

int main() {

    int caseNum;
    scanf("%d", &caseNum);
    while (caseNum--) {
        char a[1005], b[1005];
        scanf("%s%s", a, b);
        number n1(a), n2(b);
        gcd(n1, n2);
    }

    return 0;
}                                 