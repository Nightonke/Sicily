// Problem#: 1388
// Submission#: 2380736
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int i = 0, j, sum = 0;
    char a, b[1000];
    while (1) {
        a = getchar();
        if (a == '#')
            break;
        while(a != '\n') {
            b[i] = a;
            i++;
            a = getchar();
        }
        for (j = 1; j <= i; j++) {
            if (b[j - 1] == ' ' )
                b[j - 1] = 64;
            sum = sum + j * (b[j - 1] - 64);
        }
        printf("%d\n", sum);
        sum = 0;
        i = 0;
    }
    return 0;
}                                 