// Problem#: 1775
// Submission#: 2699356
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

struct priority {
    int order;
    int pri;
};

int should_change(int t1[], int t2[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (t1[i] > t2[i])
            return -1;
        else if (t1[i] < t2[i])
            return 1;
    }
    return 0;
}

int main() {
    priority p[110];
    int t, n, m, i, j, k, o[110], q, b[110][11], a[110][11];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        scanf("%d", &q);
        while (q--) {
            for (i = 0; i < n; i++)
                o[i] = i;
            for (i = 0; i < m; i++) {
                scanf("%d", &p[i].pri);
                p[i].order = i;
            }
            for (i = 0; i < m; i++) {
                for (j = 0; j < m - i - 1; j++) {
                    if (p[j].pri > p[j + 1].pri) {
                        priority temp;
                        temp = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = temp;
                    }
                }
            }
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    b[j][i] = a[j][p[i].order];
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if (should_change(b[j], b[j + 1], m) == -1) {
                        for (k = 0; k < m; k++) {
                            int temp = b[j][k];
                            b[j][k] = b[j + 1][k];
                            b[j + 1][k] = temp;
                        }
                        int temp = o[j];
                        o[j] = o[j + 1];
                        o[j + 1] = temp;
                    }
                }
            }
            printf("%d", o[0]);
            for (i = 1; i < n; i++) {
                printf(" %d", o[i]);
            }
            printf("\n");
        }
    }
    return 0;
}                                 