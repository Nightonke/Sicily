// Problem#: 4314
// Submission#: 2373243
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, a, b, i;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        for (i = 2; i <= a && i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                printf("No\n");
                break;
            }
        }
        if (i > a || i > b)
            printf("Yes\n");
    }
    return 0;
}                                 