// Problem#: 1325
// Submission#: 2519403
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int getsum(int a) {
    int sum;
    sum = a;
    while (a > 0) {
        sum = sum + a % 10;
        a = a / 10;
    }
    return sum;
}
int main() {
    int t, n, start;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n > 60)
            start = n - 60;
        else
            start = 1;
        while (start < n) {
            if (getsum(start) == n) {
                printf("%d\n", start);
                break;
            }
            start++;
        }
        if (start == n)
            printf("0\n");
    }
    return 0;
}                                 