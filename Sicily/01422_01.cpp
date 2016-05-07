// Problem#: 1422
// Submission#: 2770534
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main(){int n,m,h,v,c,a,b;while(~scanf("%d%d",&m,&n)){a=n;b=m;c=a%b;while(c){a=b;b=c;c=a%b;}h=n/b-1;v=m/b-1;if(h&1)if(v&1)printf("A");else printf("D");else if(v&1)printf("B");else printf("C");printf(" %d\n",h+v);}return 0;}                                 