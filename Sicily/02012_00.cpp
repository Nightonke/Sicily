// Problem#: 2012
// Submission#: 2753903
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main(){int n,i,j,m,k,x;char t[1001];while(~scanf("%d\n",&n)){for(i=0,x=0,k=0;i<n;i++){gets(t);for(j=0,m=0;j<n;j++){if(t[j]&1)m++;}if(m>x){x=m;k=i;}}printf("%d\n",k+1);}return 0;}                                 