// Problem#: 1510
// Submission#: 2380552
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, qvdiao, i = 0, counter = 1, j;
    char a[100], e;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &qvdiao);
        e = getchar();
        while(e != '\n') {
            a[i] = e;
            i++;
            e = getchar();
        }
        a[qvdiao] = 'a';
        printf("%d", counter);
        for(j = 0; j < i; j++) {
            if (a[j] != 'a')
                printf("%c", a[j]);
        }
        printf("\n");
        counter++;
        i = 0;
    }
    return 0;
}                                 