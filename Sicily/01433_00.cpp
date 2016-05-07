// Problem#: 1433
// Submission#: 2450278
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
int cmp ( const void *a , const void *b){
        return *(int *)a - *(int *)b;
}
int main() {
    int i, t, n, a[1000];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        qsort(a, n, sizeof(a[0]), cmp);
        printf("%d\n", (a[n - 1] - a[0]) * 2);
    }
    return 0;
}                                 