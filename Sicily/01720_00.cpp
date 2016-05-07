// Problem#: 1720
// Submission#: 3585243
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
int main() {
    int t,a,b,i;
    t=0;
    while (scanf("%d %d",&a,&b)!=EOF) {
        t++;
        printf("case %d:\n",t);
        if (a==0) {
            printf("1 * B 1\n");
            printf("1 B R 2\n");
            printf("2 * * 1\n");
            printf("2 B B 50\n");
            for (i=0;i<b;i++) {
                printf("%d B * %d\n",i+50,i+50);
                printf("%d * R %d\n",i+50,i+51);
            }
        } else {
            printf("1 * B 1\n");
            printf("1 B R 2\n");
            printf("2 * B 3\n");
            printf("3 B L 4\n");
            printf("4 B * 5\n");
            printf("5 * L 5\n");
            printf("5 B B 6\n");
            for (i=0;i<a-1;i++) {
                printf("%d B * %d\n",i+6,i+6);
                printf("%d * L %d\n",i+6,i+7);
            }
            printf("%d B R 20\n",i+6);
            printf("20 * R 20\n");
            printf("20 B R 2\n");
            printf("2 B R 30\n");
            for (i=0;i<b;i++) {
                printf("%d B * %d\n",i+30,i+30);
                printf("%d * R %d\n",i+30,i+31);
            }
        }
    }
    return 0;
}                                 