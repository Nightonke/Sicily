// Problem#: 2401
// Submission#: 2836588
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, sh, sm, lh, lm, lm_sum, eh;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d%d", &sh, &sm, &lh, &lm);
        lm_sum = lh * 60 + lm;
        eh = sh + (lm_sum + sm) / 60;
        printf("------+---------\n time | elapsed\n------+---------\n");
        for (int i = sh; i <= eh; i++) {
            int out_i;
            out_i = (i - 1) % 12 + 1;
            printf("%2d:XX | XX", out_i);
            if (i == sh)
                if (sm == 0)
                    printf("\n");
                else
                    printf(" - %d\n", sm);
            else
                printf(" + %d\n", (60 - sm) + (i - sh - 1) * 60);
        }
    }
    return 0;
}                                 