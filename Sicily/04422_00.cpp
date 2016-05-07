// Problem#: 4422
// Submission#: 2652056
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, m, num, counter, l, r, p;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &num);
        l = 0;
        r = m - 1;
        counter = 0;
        while (num--) {
            scanf("%d", &p);
            p--;
            if (p >= l && p <= r) {
                continue;
            }
            if (p < l) {
                while (l > p) {
                    l--;
                    r--;
                    counter++;
                }
            }
            if (p > r) {
                while (p > r) {
                    l++;
                    r++;
                    counter++;
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 