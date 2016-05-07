// Problem#: 1395
// Submission#: 2454906
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, i, length;
    char b[1000], a[1100];
    scanf("%d\n", &n);
    while (n--) {
        gets(b);
        length = strlen(b);
        if (length == 1) {
            printf("%s\n", b);
            continue;
        }
        a[0] = '0';
        strcat(a, b);
        length++;
        for (i = length; i >= 2; i--) {
            if (a[i - 1] >= '5')
                a[i - 2]++;
        }
        if (a[0] != '0' && a[1] > '9') {
            printf("%c", a[0]);
            for (i = 0; i < length - 1; i++)
                printf("0");
            printf("\n");
        }
        if (a[1] <= '9') {
            printf ("%c", a[1]);
            for (i = 0; i < length - 2; i++)
                printf("0");
            printf("\n");
        }
        for (i = 0; i < length; i++)
            a[i] = '\0';
    }
    return 0;
}                                 