// Problem#: 9562
// Submission#: 2746255
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int s[1005][1005];

int main() {
    int i, j, k, a[1005], n;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    
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
        a[0] = (s[0][1] - s[1][2] + s[2][0]) / 2;
        a[1] = s[0][1] - a[0];
        for (k = 2; k < n; k++) {
            a[k] = s[0][k] - a[0];
        }
    }
    
    if (n == 2) {
        printf("1 1\n");
    } else {
        printf("%d", a[0]);
        for (i = 1; i < n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    
    return 0;
}                                 