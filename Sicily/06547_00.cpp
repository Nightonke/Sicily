// Problem#: 6547
// Submission#: 2521951
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int i, n, kongzhi;
    while (scanf("%d", &n), n != -1) {
        kongzhi = 0;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                kongzhi = 1;
                break;
            }
        }
        if (kongzhi || n == 1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}                                 