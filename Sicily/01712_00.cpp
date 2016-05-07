// Problem#: 1712
// Submission#: 2501055
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int length, i, counter1;
    char a[100];
    while (scanf("%s", a), a[0] != '#') {
        length = strlen(a);
        counter1 = 0;
        for (i = 0; i < length; i++) {
            if (a[i] == '1')
                counter1++;
        }
        if (counter1 % 2 == 0 && a[length - 1] == 'e') {
            a[length - 1] = '\0';
            printf("%s0\n", a);
        }
        if (counter1 % 2 == 0 && a[length - 1] == 'o') {
            a[length - 1] = '\0';
            printf("%s1\n", a);
        }
        if (counter1 % 2 == 1 && a[length - 1] == 'o') {
            a[length - 1] = '\0';
            printf("%s0\n", a);
        }
        if (counter1 % 2 == 1 && a[length - 1] == 'e') {
            a[length - 1] = '\0';
            printf("%s1\n", a);
        }
        memset(a, '\0', sizeof(a));
    }
    return 0;
}                                 