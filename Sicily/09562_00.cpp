// Problem#: 9562
// Submission#: 2746301
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main(){int i,k,a[2],n,temp,s[1001],s12,s20;scanf("%d",&n);if(n>=3){for(i=0;i<n;i++)scanf("%d",&s[i]);for(i=0;i<n+1;i++){scanf("%d",&temp);if(i==2)s12=temp;if (i==n)s20=temp;}a[0]=(s[1]-s12+s20)/2;a[1]=s[1]-a[0];printf("%d %d",a[0],a[1]);for(k=2;k<n;k++)printf(" %d",s[k]-a[0]);printf("\n");}if(n==2)printf("1 1\n");return 0;}                                 