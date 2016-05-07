// Problem#: 1014
// Submission#: 2346827
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int ceshi, mod1, sum1, mod2, sum2, mod3, sum3, ding=2992;
    while (ding <= 9999) {
        sum1=sum2=sum3=0;
        ceshi = ding;
        while (ceshi != 0) {
            mod1 = ceshi % 10;
            sum1 = sum1 +mod1;
            ceshi = ceshi / 10;}
        ceshi = ding;
        while (ceshi != 0) {
            mod2 = ceshi % 12;
            sum2 = sum2 + mod2;
            ceshi = ceshi / 12;}
        ceshi = ding;
        while (ceshi != 0) {
            mod3 = ceshi % 16;
            sum3 = sum3 + mod3;
            ceshi = ceshi / 16;}
        if (sum1 == sum2 && sum2 == sum3)
            printf("%d\n", ding);
        ding++;}
    return 0;
}                                 