// Problem#: 1497
// Submission#: 2796248
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int a[260];

void trans(int times) {
    int temp[2 * times + 1];
    for (int i = 1; i <= times; i++) {
        temp[2 * i - 1] = (a[i] + a[i + times]) / 2;
        temp[2 * i] = (a[i] - a[i + times]) / 2;
    }
    for (int i = 1; i <= 2 * times; i++) {
        a[i] = temp[i];
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int times = 1;
        while (times <= n / 2) {
            trans(times);
            times *= 2;
        }
        for (int i = 1; i <= n; i++) {
            if (i != 1)
                printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}                                 