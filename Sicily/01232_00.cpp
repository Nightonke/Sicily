// Problem#: 1232
// Submission#: 2435948
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, m, sum, i, add;
    scanf("%d", &n);
    while (n--) {
        sum = 0;
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            scanf("%d", &add);
            sum = sum + add;
        }
        printf("%d\n", sum - m + 1);
    }
    return 0;
}                                 