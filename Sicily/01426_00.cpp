// Problem#: 1426
// Submission#: 2771887
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

struct phone {
    char aa[11];
}p[10001];

bool cmp(const phone &a, const phone &b) {
    return strcmp(a.aa, b.aa) <= 0;
}

bool is_ok(int n) {
    int k, j;
    for (int i = 0; i < n - 1; i++) {
        for (k = 0, j = i + 1; k < (int)strlen(p[i].aa) && k < (int)strlen(p[j].aa); k++) {
            if (p[i].aa[k] != p[j].aa[k]) {
                break;
            }
        }
        if ((k >= (int)strlen(p[i].aa)) || (k >= (int)strlen(p[j].aa))) {
            //cout << i << j << k << endl;
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n, case_num;
    scanf("%d\n", &case_num);
    while (case_num--) {
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++) {
            memset(p[i].aa, '\0', sizeof(p[i].aa));
            gets(p[i].aa);
        }
        sort(p, p + n, cmp);
        if (is_ok(n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}                                 