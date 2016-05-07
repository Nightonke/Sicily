// Problem#: 3499
// Submission#: 2367839
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
int cmp ( const void *a , const void *b){
        return *(int *)a - *(int *)b;
    }
int main () {
    int t, m, i = 0, j, a[1001];
    float sum = 0, pingjun;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &a[i]);
            i++;}
        qsort(a, i - 1, sizeof(a[0]), cmp);
        for (j = 1; j <= i - 2;j++) {
            sum = sum + a[j];}
        pingjun = sum / (i - 2);
        printf("%.2f\n", pingjun);
        sum = 0;
        i = 0;
    }
    return 0;
}                                 