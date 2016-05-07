// Problem#: 1144
// Submission#: 2334812
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int a[10], h, geshu=0, i, j;
    for(i=0;i<10;i++)
        scanf("%d", &a[i]);
    scanf("%d", &h);
    for(j=0;j<10;j++) {
        if(h+30>=a[j])
            geshu++;}
    printf("%d\n", geshu);
    return 0;
    }                                 