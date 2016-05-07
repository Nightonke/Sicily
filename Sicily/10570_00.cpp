// Problem#: 10570
// Submission#: 2811108
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
int w,n,t,a,p;int main(){char c;scanf("%d%d",&w,&n);w--;while(n--){scanf("%d %c",&t,&c);a+=t;if(a>209&&!p)p=1,printf("%d\n",w+1);if(c=='T')w=(w+1)%8;}return 0;}                                 