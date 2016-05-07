// Problem#: 1792
// Submission#: 2700439
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    bool a[1450];
    int n, i, j, h1, h2, m1, m2, max_length , mem1, mem2;
    while (scanf("%d", &n), n) {
        memset(a, true, sizeof(a));
        for (i = 0; i < n; i++) {
            scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
            for (j = h1 * 60 + m1; j < h2 * 60 + m2; j++) {
                a[j] = false;
            }
        }
        max_length = 0;
        a[1440] = false;
        for (i = 0; i <= 1440; i++) {
            for (j = i; j <= 1440 && a[i]; j++) {
                if (a[j] == false && j != 1440) {
                    if (max_length < j - i) {
                        max_length = j - i;
                        mem1 = i;
                        mem2 = j;
                    }
                    break;
                }
                if (a[j] == false && j == 1440) {
                    if (max_length < j - i - 1) {
                        max_length = j - i - 1;
                        mem1 = i;
                        mem2 = j - 1;
                    }
                    break;
                }
            }
        }
        if (max_length == 0)
            printf("Poor Hengheng\n");
        else {
            if (mem1 / 60 <= 9) {
                printf("0%d:", mem1 / 60);
            } else {
                printf("%d:", mem1 / 60);
            }
            if (mem1 % 60 <= 9) {
                printf("0%d ", mem1 % 60);
            } else {
                printf("%d ", mem1 % 60);
            }
            if (mem2 / 60 <= 9) {
                printf("0%d:", mem2 / 60);
            } else {
                printf("%d:", mem2 / 60);
            }
            if (mem2 % 60 <= 9) {
                printf("0%d\n", mem2 % 60);
            } else {
                printf("%d\n", mem2 % 60);
            }
        }
    }
    return 0;
}                                 