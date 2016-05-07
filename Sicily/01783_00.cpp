// Problem#: 1783
// Submission#: 2516164
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, j, have_number, length, i, k, max, jilu, zj, u;
    char a[101] = {'\0'}, b[101] = {'\0'};
    scanf("%d\n", &t);
    while(t--) {
        j = 0;
        have_number = 0;
        scanf("%s", a);
        length = i = 0;
        while (a[i++] != '\0')
            length++;
        for (i = 0; i < length; i++) {
            if (a[i] != '0') {
                b[j++] = a[i];
                have_number = 1;
            }
            if ((a[i] == '0' || i == length - 1) && have_number == 1) {
                for (k = 0; k < j; k++) {
                    max = b[k];
                    jilu = k;
                    for (u = k + 1; u < j; u++) {
                        if (max < b[u]) {
                            max = b[u];
                            jilu = u;
                        }
                    }
                    zj = b[jilu];
                    b[jilu] = b[k];
                    b[k] = zj;
                }
                b[j] = '\0';
                printf("%s", b);
                j = 0;
                have_number = 0;
            }
            if (a[i] == '0')
                printf("0");
        }
        printf("\n");
        have_number = j = 0;
        for (i = 0; i < 101; i++)
            a[i] = b[i] = '\0';
    }
    return 0;
}                                 