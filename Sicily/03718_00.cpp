// Problem#: 3718
// Submission#: 2367888
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main () {
    int n, m, i, j, k, counter = 0, linshi;
    float a[100];
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        a[i] = 0;
    i = 0;
    for(j = 1; j <=n; j++) {
        for(k = 1; k <=m; k++) {
            scanf("%d", &linshi);
            a[i] = a[i] + linshi;
        }
        if (a[i] / m < 60)
            counter++;
        i++;
    }
    for (i = 0; i <n; i++)
        printf("%.2f\n", a[i]/m);
    printf("%d\n", counter);
    return 0;
}                                 