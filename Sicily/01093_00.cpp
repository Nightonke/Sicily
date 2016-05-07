// Problem#: 1093
// Submission#: 2693122
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int w[5], r[5];

int judge_try_times(int size) {
    if (size <= w[1])
        return 3;
    else if (size > w[1] && size <= w[2])
        return 2;
    else if (size > w[2] && size <= w[3])
        return 1;
    else
        return 0;
}

int main() {
    int counter = 0, i, t, s, min, memo;
    while (scanf("%d", &w[1]) == 1) {
        counter++;
        printf("Set number %d:\n", counter);
        scanf("%d%d%d%d%d%d", &r[1], &w[2], &r[2], &w[3], &r[3], &r[4]);
        w[4] = 1000;
        while (scanf("%d", &s), s) {
            t = judge_try_times(s);
            for (i = 1; i <= 4; i++) {
                if (w[i] >= s) {
                    min = s * r[i];
                    memo = 0;
                    break;
                }
            }
            for (i = 3 - t + 1; i <= 3; i++) {
                memo = (w[i] + 1) * r[i + 1] < min ? (w[i] + 1) - s : memo;
                min = (w[i] + 1) * r[i + 1] < min ? (w[i] + 1) * r[i + 1] : min;
            }
            printf("Weight (%d) has best price $%d (add %d pounds)\n", s, min, memo);
        }
        printf("\n");
    }
    return 0;
}                                 