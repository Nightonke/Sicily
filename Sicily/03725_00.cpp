// Problem#: 3725
// Submission#: 2367896
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main () {
    int n, linshi, max = 0, zj;
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        while (n--) {
            scanf("%d", &linshi);
            if(max < linshi) {
                zj = linshi;
                linshi = max;
                max = zj;}
        }
        printf("%d\n", max);
        max = 0;
    }
    return 0;
}                                 