// Problem#: 4427
// Submission#: 2701516
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

bool judge(int i, int a, int b) {
    if (a % i == 0 && b % i == 0)
        return true;
    else
        return false;
}

int main() {
    int t, a, b, low, high, i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &a, &b, &low, &high);
        for (i = high; i >= low; i--) {
            if (judge(i, a, b)) {
                break;
            }
        }
        if (i < low)
            printf("No answer\n");
        else
            printf("%d\n", i);
    }
    return 0;
}                                 