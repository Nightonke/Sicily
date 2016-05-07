// Problem#: 1051
// Submission#: 2339605
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main(){
    float dia, re, t, dis, v;
    int i=1;
    while (1) {
        scanf("%f%f%f", &dia, &re, &t);
        if(re == 0)
            break;
        dis=3.1415927*dia*re/63360;
        v=dis/(t/3600);
        printf("Trip #%d: %.2f %.2f\n", i, dis, v);
        i++;}
    return 0;
}                                 