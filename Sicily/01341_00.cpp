// Problem#: 1341
// Submission#: 2366226
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
int cmp ( const void *a , const void *b){
        return *(int *)a - *(int *)b;
    }
int main () {
    int a[101], n, i = 0, j, k, counter = 0, h;
    while (1) {
        scanf("%d", &n);
        if (n == EOF)
            break;
        while (n--) {
        scanf("%d", &a[i]);
        i++;}
        qsort(a, i, sizeof(a[0]), cmp);
        for (k = 0; k < i; k++)
            if (a[k] == a[k+1]) {
                counter++;
                    a[k] = 0;}
    printf("%d\n", i - counter);
    for(j = 0; j < i - 1; j++)
        if (a[j] != 0)
            printf("%d ", a[j]);
    printf("%d\n", a[i-1]);
    i = 0;
    counter = 0;}
    return 0;
}                                 