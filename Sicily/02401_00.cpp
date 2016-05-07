// Problem#: 2401
// Submission#: 2836589
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main(){int n,a,b,c,d,e,i,o;scanf("%d",&n);while(n--){scanf("%d%d%d%d",&a,&b,&c,&d);e=a+(c*60+d+b)/60;printf("------+---------\n time | elapsed\n------+---------\n");for(i=a;i<=e;i++){o=(i-1)%12+1;printf("%2d:XX | XX",o);if(i==a)if(!b)printf("\n");else printf(" - %d\n",b);else printf(" + %d\n",(60-b)+(i-a-1)*60);}}return 0;}                                 