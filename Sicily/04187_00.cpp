// Problem#: 4187
// Submission#: 2368954
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
int cmp ( const void *a , const void *b){
        return *(int *)a - *(int *)b;
    }
int main () {
    int t, i, a[3];
    scanf("%d", &t);
    while (t--) {
        for(i = 0; i <=2; i++)
            scanf("%d", &a[i]);
        qsort(a, 3, sizeof(a[0]), cmp);
        if ((a[2] - a[1] < a[0]) && (a[0] + a[1] > a[2]))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}                                 