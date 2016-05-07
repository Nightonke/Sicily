// Problem#: 1497
// Submission#: 2796257
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int a[260];
int temp[260];
int half_i;
int doubletimes;
int i;

void trans(int times) {
    
    doubletimes = times << 1;
    
    for (i = 2; i <= doubletimes; i += 2) {
        half_i = i >> 1;
        temp[i - 1] = (a[half_i] + a[half_i + times]) >> 1;
        temp[i] = temp[i - 1] - a[half_i + times];
    }
    for (i = 1; i <= doubletimes; i++) {
        a[i] = temp[i];
    }
}

int main() {
    int n, times, temp_n;
    while (scanf("%d", &n) && n) {
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        times = 1;
        temp_n = n >> 1;
        while (times <= temp_n) {
            trans(times);
            times <<= 1;
        }
        printf("%d", a[1]);
        for (i = 2; i <= n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}                                 