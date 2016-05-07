// Problem#: 1200
// Submission#: 2383482
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
int cmp ( const void *a , const void *b){
        return *(long long int *)a - *(long long int *)b;
}
int main() {
    long long int n, i, a[1000], counter = 0;
    while (1) {
        scanf("%lld", &n);
        if (n == 0)
            break;
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        qsort(a, n, sizeof(a[0]), cmp);
        for (i = 0; i < n; i++) {
            if (a[i] == a[i+1]) {
                counter++;
            }
            if (a[i] != a[i+1]) {
                if (counter % 2 == 0) {
                    printf("%lld\n", a[i]);
                    break;
                }
                if (counter % 2 != 0) {
                    counter = 0;
                }
            }
        }
        counter = 0;
    }
    return 0;
}                                 