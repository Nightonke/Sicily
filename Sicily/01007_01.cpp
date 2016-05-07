// Problem#: 1007
// Submission#: 2389331
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, i, j, k, h, m, counter = 0, counter1, n1, lieshu, kongzhi, counter2 = 0;
    char a[200], c;
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        counter = 0;
        i = 2 * n - 1;
        j = 1;
        k = 0;
        h = 0;
        m = 0;
        kongzhi = 0;
        c = getchar();
        while (1) {
            if (c >= 'a' && c <= 'z') {
                a[m] = c;
                m++;
                counter++;}
            if (c == '\n' && kongzhi == 1)
                break;
            if (c == '\n')
                kongzhi = 1;
            c = getchar();}
        counter1 = counter;
        n1 = n;
        lieshu = counter1 / n1;
        while (n--) {
            while (1) {
                printf("%c", a[k]);
                counter2++;
                if(counter2 == lieshu)
                    break;
                k = k + i;
                printf("%c", a[k]);
                counter2++;
                if(counter2 == lieshu)
                    break;
                k = k + j;}
            lieshu = counter1 / n1;
            counter2 = 0;
            h++;
            k = h;
            i = i - 2;
            j = j + 2;}
        printf("\n");}
    return 0;
}                                 