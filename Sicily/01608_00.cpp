// Problem#: 1608
// Submission#: 2305717
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main(){
    int c0=0, c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0, n, i, num, e;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &num);
        for(i=1;i<=num;i++){
            e=i;
            while(e!=0){
                switch(e%10){
                case 0 : c0++;
                break;
            case 1 : c1++;
            break;
             case 2 : c2++;
            break;
             case 3 : c3++;
            break;
             case 4 : c4++;
            break;
             case 5 : c5++;
            break;
             case 6 : c6++;
            break;
             case 7 : c7++;
            break;
             case 8 : c8++;
            break;
             case 9 : c9++;
            break;}
                e=e/10;}}
        printf("%d %d %d %d %d %d %d %d %d %d\n", c0,c1,c2,c3,c4,c5,c6,c7,c8,c9);
    c0=c1=c2=c3=c4=c5=c6=c7=c8=c9=0;}
    return 0;
}                                 