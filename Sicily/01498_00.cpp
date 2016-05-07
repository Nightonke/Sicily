// Problem#: 1498
// Submission#: 2592140
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
char a[20][1000000];

int catch1(int i, int j, int posi) {
    int length, k;
    length = strlen(a[j]);
    for (k = 0; k < length; k++) {
        a[i][posi + k] = a[j][k];
    }
    return k + posi;
}

void make() {
    int i, posi, j;
    for (i = 1; i <= 16; i++) {
        a[i][0] = '{';
        posi = 1;
        for (j = 0; j < i; j++) {
            posi = catch1(i, j, posi);
            if (j != i - 1) {
                a[i][posi++] = ',';
            }
        }
        a[i][posi] = '}';
        a[i][posi + 1] = '\0';
    }
}

int main() {
    a[0][0] = '{';
    a[0][1] = '}';
    char add1[100000], add2[100000];
    int t, i, ad1, ad2;
    //int judge[] = {2, 4, 9, 19, 39, 79, 159, 319, 639, 1279, 2559, 5119, 10239, 20479, 40959, 81919};
    make();
    scanf("%d\n", &t);
    while (t--) {
        scanf("%s", add1);
        scanf("%s", add2);
        for (i = 0; i <= 15; i++) {
            if (strcmp(add1, a[i]) == 0) {
                ad1 = i;
                break;
            }
        }
        for (i = 0; i <= 15; i++) {
            if (strcmp(add2, a[i]) == 0) {
                ad2 = i;
                break;
            }
        }
        printf("%s\n", a[ad1 + ad2]);
    }
    return 0;
}                                 