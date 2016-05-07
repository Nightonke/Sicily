// Problem#: 13907
// Submission#: 3660142
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
int main(){int a,b,c,d,i,j;double s=0;scanf("%d%d%d%d",&a,&b,&c,&d);for(i=a;i<=b;i++)for(j=c;j<=d;j++)s+=i+j;s/=(b-a+1)*(d-c+1);scanf("%d%d%d%d",&a,&b,&c,&d);s*=(b-a+1)*(d-c+1);for(i=a;i<=b;i++)for(j=c;j<=d;j++)s-=i+j;printf(s?s>0?"Gunnar\n":"Emma\n":"Tie\n");return 0;}                                 