// Problem#: 14256
// Submission#: 3672439
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    int temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {

    int caseNum;
    scanf("%d", &caseNum);
    while (caseNum--) {
        bool isOK = false;
        int x;
        scanf("%d", &x);
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                if (gcd(i, x / i) == 1) {
                    printf("YES\n");
                    isOK = true;
                    break;
                }
            }
        }
        if (!isOK) printf("NO\n");
    }

    return 0;
}                                 