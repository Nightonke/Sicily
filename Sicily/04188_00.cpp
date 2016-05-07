// Problem#: 4188
// Submission#: 2371777
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int i = 0, t, j, a[4000];
    long long int linshi;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &linshi);
        while(linshi != 0) {
            a[i] = linshi % 2;
            i++;
            linshi = linshi / 2;}
        for(j = i - 1; j >0; j--)
            printf("%d", a[j]);
        printf("%d\n", a[0]);
        i = 0;
    }
    return 0;
}                                 