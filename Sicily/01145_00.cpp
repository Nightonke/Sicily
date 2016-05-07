// Problem#: 1145
// Submission#: 2348317
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a[10001], i, l, j1, j2, counter, n;
    scanf("%d", &l);
    for (i=0; i<=l; i++)
        a[i] = 1;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &j1, &j2);
        for (; j1<=j2; j1++) {
            a[j1] = 0;}}
    for(i=0; i<=l; i++)
        if(a[i] == 1)
            counter++;
    printf("%d\n", counter);
    return 0;
}                                 