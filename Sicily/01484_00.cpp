// Problem#: 1484
// Submission#: 2773617
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int m, s, t, go_s, left_t, control_blank = 0;
    while (~scanf("%d%d%d", &m, &s, &t)) {
        if (control_blank) {
            printf("\n");
        }
        go_s = 0;
        left_t = t;
        control_blank = 1;
        while (m >= 10 && left_t >= 1 && s - go_s > 0) {
            go_s += 60;
            left_t -= 1;
            m -= 10;
        }
        while (6 <= m && m < 10 && left_t >= 2 && s - go_s >= 17 + 1) {
            go_s += 60;
            left_t -= 2;
            m = m + 4 - 10;
        }
        while (2 <= m && m < 6 && left_t >= 3 && s - go_s >= 17 + 17 + 1) {
            go_s += 60;
            left_t -= 3;
            m = m + 4 + 4 - 10;
        }
        while (0 <= m && m < 2 && s - go_s > 7 * 17 && left_t >= 7) {
            go_s += 60 + 60;
            left_t -= 7;
            m = m + 4 + 4 + 4 - 10 + 4 + 4 - 10;
        }
        while (0 < s - go_s && left_t > 0) {
            go_s += 17;
            left_t -= 1;
        }
        if (go_s < s) {
            printf("No\n%d\n", go_s);
        } else {
            printf("Yes\n%d\n", t - left_t);
        }
    }
    return 0;
}                                 