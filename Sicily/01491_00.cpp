// Problem#: 1491
// Submission#: 2450326
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int t, length, i, sum, counter;
    char a[1100];
    scanf("%d", &t);
    while (t--) {
        sum = counter = 0;
        scanf("%s", a);
        length = strlen(a);
        for (i = 0; sum < length; i++) {
            if (a[i] == a[i + 1]) {
                counter++;
            }
            if (a[i] != a[i + 1]) {
                printf("%d%c", counter + 1, a[i]);
                sum = sum + counter + 1;
                counter = 0;
            }
        }
        printf("\n");
    }
    return 0;
}                                 