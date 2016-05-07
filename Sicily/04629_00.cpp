// Problem#: 4629
// Submission#: 2332601
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, a, b, c, d, i, zi, mu;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d%d%d", &a,&b,&c,&d);
        zi=a*d+c*b;
        mu=b*d;
        for(i=2;(i<=zi)||(i<=mu);i++) {
            if((zi%i==0)&&(mu%i==0)) {
                zi=zi/i;
                mu=mu/i;
                i=2;}}
        if(mu==1)
            printf("%d\n", zi);
        else
            printf("%d/%d\n", zi, mu);}
    return 0;
}                                 