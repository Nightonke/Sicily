// Problem#: 1122
// Submission#: 2486216
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int k, m, kongzhi, i, havechosen[101], all, need, j, categories[101], u, counter;
    while (scanf("%d", &k), k > 0) {
        scanf("%d", &m);
        kongzhi = 1;
        for (i = 0; i < k; i++) {
            scanf("%d", &havechosen[i]);
        }
        for (i = 0; i < m; i++) {
            scanf("%d %d", &all, &need);
            for (j = 0; j < all; j++) {
                scanf("%d", &categories[j]);
            }
            counter = 0;
            for (u = 0; u < k; u++) {
                for (j = 0; j < all; j++) {
                    if (havechosen[u] == categories[j])
                        counter++;
                }
            }
            if (counter < need)
                kongzhi = 0;
        }
        if (kongzhi)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}                                 