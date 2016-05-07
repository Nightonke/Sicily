// Problem#: 9562
// Submission#: 2746280
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int main() {
    int i, k, a[2], n, temp, s[1005], s12, s20;
    
    scanf("%d", &n);
    /*for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &s[i][j]);
        }
    }*/
    
    memset(a, 0, sizeof(a));
    /*for (i = 0; i < n && n >= 3; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                a[i] = (s[i][j] - s[j][k] + s[k][i]) / 2;
                a[j] = s[i][j] - a[i];
                a[k] = s[i][k] - a[i];
            }
        }
    }*/
    
    if (n >= 3) {
        for (i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        for (i = 0; i < n + 1; i++) {
            scanf("%d", &temp);
            if (i == 2)
                s12 = temp;
            if (i == n)
                s20 = temp;
        }
        a[0] = (s[1] - s12 + s20) / 2;
        a[1] = s[1] - a[0];
        printf("%d %d", a[0], a[1]);
        for (k = 2; k < n; k++) {
            printf(" %d", s[k] - a[0]);
        }
        printf("\n");
    }
    
    if (n == 2) {
        printf("1 1\n");
    }
    return 0;
}                                 