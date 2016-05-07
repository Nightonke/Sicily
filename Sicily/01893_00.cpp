// Problem#: 1893
// Submission#: 2760078
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n;
    long long ans;
    while (scanf("%d", &n)&&n) {
        if (n == 1) {
            printf("1\n");
            continue;
        }
        ans = 1;
        int i = 2;
        n--;
        while (n--) {
            ans = (4 * i - 2) * ans / (i + 1);
            i++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}                                 