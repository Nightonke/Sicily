// Problem#: 1201
// Submission#: 2437796
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int n, counter = 1, longa, longb, longer, i, j, kongzhi, weishu;
    char a[100] = {0}, b[100] = {0}, c[100] = {0}, a1[100] = {0}, b1[100] = {0};
    scanf("%d", &n);
    while (n--) {
        j = kongzhi = weishu = 0;
        scanf("%s %s", a1, b1);
        longa = strlen(a1);
        longb = strlen(b1);
        for (i = longa - 1; i >= 0; i--) {
            a[j] = a1[i];
            j++;
        }
        j = 0;
        for (i = longb - 1; i >= 0; i--) {
            b[j] = b1[i];
            j++;
        }
        longer = longa;
        if (longa < longb)
            longer = longb;
        for (i = 0; i < longa; i++)
            a[i] = a[i] - '0';
        for (i = 0; i < longb; i++)
            b[i] = b[i] - '0';
        for (i = 0; i < longer; i++) {
            c[i] = c[i] + a[i] + b[i];
            c[i + 1] = c[i] / 2;
            c[i] = c[i] % 2;
        }
        if (c[i] != 0)
            longer++;
        printf("%d ", counter);
        counter++;
        for (i = longer - 1; i >= 0; i--) {
            if (c[i] == 1)
                kongzhi = 1;
            if (kongzhi == 1)
                printf("%c", c[i] + '0');
            a[i] = b[i] = c[i] = 0;
            weishu++;
        }
        if (weishu == longer && kongzhi == 0)
            printf("0");
        printf("\n");
    }
    return 0;
}                                 