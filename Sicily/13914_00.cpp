// Problem#: 13914
// Submission#: 3675895
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
    bool possible = true;
    int c, n, m = 0, l, e, w;
    scanf("%d%d", &c, &n);
    while (n && n--) {
        scanf("%d%d%d", &l, &e, &w);
        if (!(0 <= l && l <= m)) possible = false;
        m -= l;
        if (!(0 <= e && e <= c - m)) possible = false;
        m += e;
        if (0 > w || (c > m && w > 0)) possible = false;
    }
    while (n--) scanf("%d%d%d", &l, &e, &w);
    printf(possible && !m ? "possible\n" : "impossible\n");
    return 0;
}                                 