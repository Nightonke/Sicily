// Problem#: 1639
// Submission#: 2608100
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
char out[100000];

int is_num(char n) {
    if (n >= '0' && n <= '9')
        return 1;
    return 0;
}

int is_let(char n) {
    if (n >= 'A' && n <= 'Z')
        return 1;
    return 0;
}

int is_toolong(char a1[], int length) {
    int i, sum = 0;
    for (i = 0; i < length - 2; i++) {
        if (is_num(a1[i]) && is_num(a1[i + 1]) && is_num(a1[i + 2]))
            return 1;
    }
    for (i = 0; i < length; i++) {
        if (is_num(a1[i])) {
            sum = sum * 10 + a1[i] - '0';
        }
        if (sum > 50)
            return 1;
        if (is_let(a1[i]))
            sum = 0;
    }
    return 0;
}

void solve(char a2[], int length) {
    int sum = 0, k = 0, i, j;
    for (i = 0; i < length; i++) {
        if (is_num(a2[i])) {
            sum = sum * 10 + a2[i] - '0';
        }
        if (is_let(a2[i])) {
            if (sum == 0)
                out[k++] = a2[i];
            else {
                for (j = 0; j < sum; j++) {
                    out[k++] = a2[i];
                }
            }
            sum = 0;
        }
    }
}

int main() {
    int length;
    char a[100] = {'\0'};
    while (gets(a)) {
        if (a[0] == '\0') {
            printf("\n");
            continue;
        }
        length = strlen(a);
        if (length > 50) {
            printf("TOO LONG\n");
            continue;
        }
        if (is_toolong(a, length)) {
            printf("TOO LONG\n");
            continue;
        }
        memset(out, '\0', sizeof(out));
        solve(a, length);
        if (strlen(out) > 50) {
            printf("TOO LONG\n");
            continue;
        }
        printf("%s\n", out);
        memset(a, '\0', sizeof(a));
    }
    return 0;
}                                 