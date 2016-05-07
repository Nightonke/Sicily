// Problem#: 9456
// Submission#: 2772492
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
char a[100001];int main(){int r=0,l=0,s,i;gets(a);for(i=0;a[i]!='\0';i++){if(a[i]=='(')l++;else l--;if(l<0){r++;l=0;}}if(!r||!l)s=r>l?r/2:l/2;else if(r==l)s=l&1?l+1:l;else s=l&1?(l+r)/2+1:(l+r)/2;printf("%d\n",s);return 0;}                                 